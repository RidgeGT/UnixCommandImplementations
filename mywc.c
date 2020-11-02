#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#define MAXLINE 10000
#define MAXBYTES 1024

struct COUNTS
{
  int TOTAL_LINES, TOTAL_WORDS, TOTAL_CHARS;
};

struct COUNTS mywc(FILE *this_file,char *filename);

int main(int argc, char **argv)
{
	if(argv[1]!= NULL)
	{
    int i;
    struct COUNTS TOTAL_COUNTS = {0,0,0};
    struct COUNTS FILE_COUNTS = {0,0,0};
    for(i = 1; i < argc;i++)
    {
       FILE *pFile;
       
       pFile = fopen(argv[i],"r");
       if(pFile != NULL)
       {
         FILE_COUNTS = mywc(pFile,argv[i]);
         TOTAL_COUNTS.TOTAL_LINES = TOTAL_COUNTS.TOTAL_LINES + FILE_COUNTS.TOTAL_LINES;
         TOTAL_COUNTS.TOTAL_WORDS = TOTAL_COUNTS.TOTAL_WORDS + FILE_COUNTS.TOTAL_WORDS;
         TOTAL_COUNTS.TOTAL_CHARS = TOTAL_COUNTS.TOTAL_CHARS + FILE_COUNTS.TOTAL_CHARS;
         fclose(pFile);
       }
       else
       {
         printf("mywc: %s: No such file or directory\n",argv[i]);
       }
    }
    if(argc > 2)
    {
      printf(" %d %d %d total\n",TOTAL_COUNTS.TOTAL_LINES,TOTAL_COUNTS.TOTAL_WORDS,TOTAL_COUNTS.TOTAL_CHARS);
    }
	}
	else
	{
    mywc(stdin,"");
	}
	return 0;
}

struct COUNTS mywc(FILE *this_file, char *filename)
{
  char *this_string = (char*)malloc(MAXBYTES*sizeof(char));
 	int line_number,word_count,char_count = 0;
	do
	{
		fgets(this_string,MAXLINE,this_file);
    //printf("check");
    ///printf("%s",this_string); DEBUG
		if(this_string != NULL && !feof(this_file))
		{
      int check_word = 0;
			line_number = line_number + 1;
      char_count = char_count+1;
			int i;
			for(i = 0;i < strlen(this_string)-1;i++)
			{
				char_count = char_count + 1;
				if(isspace(this_string[i]))
				{
					if(check_word == 1)
					{
						check_word = 0;
					}
				}
				else
        {
          if(check_word == 0)
          {
            word_count = word_count + 1;
          }
          check_word = 1;
        }
			}
		}
	}
	while(!feof(this_file));
  free(this_string);
  if(this_file == stdin)
    printf("      %d      %d      %d\n",line_number,word_count,char_count);
  else
    printf(" %d %d %d %s\n",line_number,word_count,char_count,filename);  
  struct COUNTS these_counts = {line_number,word_count,char_count};
  return these_counts;
}
