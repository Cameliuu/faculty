#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

void main(int argc, char* argv[])
{
	DIR *dr;
	struct stat stare;
	struct dirent *data;
	int size;
	if(argv[1]==NULL)
		printf("[USAGE] : ./lab3 [TARGET]\n");

	stat(argv[1], &stare);

	if(S_ISREG(stare.st_mode))
		printf("Fisierul introdus nu este un director");
	dr=opendir(argv[1]);
	while((data=readdir(dr))!=NULL)
		{
 			if(data->d_name[0]!='.')
			{
				
				stat(data->d_name,&stare);
				printf("Nume: %s \n",data->d_name);	
				printf("Dimensiune: %u\n",stare.st_size);
		       		printf("Drepturi : %o \n",stare.st_mode);
		       		chmod(data->d_name,437);
				printf("Drepturi: %o \n",stare.st_mode);
			}
		}
	closedir(dr);
}
