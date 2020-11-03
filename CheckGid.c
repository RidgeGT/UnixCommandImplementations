/*Ridge Tejuco
06 May 2020*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
  struct stat file1, file2;
  char *filename1;
  char *filename2;
  filename1 = malloc(sizeof(argv[1]));
  filename1 = strdup(argv[1]);
  filename2 = malloc(sizeof(argv[2]));
  filename2 = strdup(argv[2]);
  if(stat(filename1,&file1) == -1)
  {
		fprintf(stderr,"%s: cannot access %s\n",argv[0],argv[1]);
		exit(1);	
  }
  printf("%s\n",filename1);
  if(stat(filename2,&file2) == -1)
  {
		fprintf(stderr,"%s: cannot access %s\n",argv[0],argv[2]);
		exit(1);	
  }
  printf("%s\n",filename2);
  if(file1.st_gid == file2.st_gid)
  {
  	printf("Group IDs for the owners of these files are the same. \n");
  }
  else
  {
  	printf("Group IDs for the owners of these two files are different. \n");
  }
  free(filename1);
  free(filename2);
  return 0;
}
