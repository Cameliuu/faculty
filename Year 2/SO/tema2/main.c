#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
void main(int argc, char* argv[])
{
	DIR *dr;
	struct dirent *entryData;
	char source[100],dest[100],ans;
	
	if(argv[1]==NULL || argv[2]== NULL)
		printf("[ + ] USAGE: ./runme [SOURCE] destination");

	strcpy(source,argv[1]);
	strcpy(dest,argv[2]);


	if((dr=opendir(dest))==NULL)
	{
		printf("\n\033[31m [ ! ] ERROR: DIRECTORY COULD NOT BE FOUND\n\033[0m [ + ]  DO YOU WANT TO CREATE IT NOW?[Y / n]: ");
		ans=getchar();
		if(tolower(ans)=='y' || ans==10)
		{
			mkdir(dest, S_IRUSR | S_IWUSR | S_IXUSR);
			printf("\n\033[32m [ + ] CREATED DESTINATION DIRECTORY");
		}
		else
		{
			return -1;
		}
	}
	list(source,dest);	
}
