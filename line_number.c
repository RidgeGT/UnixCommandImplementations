#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,char **argv)
{
	FILE *pFile;
	if(argv[1] != NULL)
	{
		pFile = fopen(argv[1],"r");
	}
	else
	{
		printf("Input the file name then press ctrl+D: ");
		char *filename = (char*)malloc(sizeof(char));
		
		if(fgets(filename,256,stdin) != NULL)
		{
			pFile = fopen(filename,"r");
		}
		else
			printf("error");

		free(filename);
	}
	if(pFile != NULL)
	{
		int line_number = 1;
		char *next_line = (char*)malloc(sizeof(char));
		do
		{
			if(fgets(next_line,1500,pFile)!=NULL)
			{
				printf("%d ",line_number);
				puts(next_line);
				line_number = line_number + 1;
			}
		}
		while(next_line != NULL);
		free(next_line);
		fclose(pFile);
	}
	return 0;
}
