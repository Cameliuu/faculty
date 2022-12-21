#include<stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
void list( char *path, char *dest)
{

	struct stat stare;
	char newPath[1000];
	char newDest[1000];
	struct dirent *entry;
	DIR *dr;
	if((dr=opendir(path))==NULL)
	{
		return -1;
	}
	 while ((entry = readdir(dr)) != NULL)
    	{
        	if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        	{
                        strcpy(newPath, path);
                        strcat(newPath, "/");
                        strcat(newPath, entry->d_name);	
			stat(newPath,&stare);


					strcpy(newDest, dest);
                                        strcat(newDest, "/");
                                        strcat(newDest, entry->d_name);
			if(S_ISDIR(stare.st_mode))
				{
					printf("\n\033[0m [ + ] FOUND %s DIRECTORY \n \033[32m[ + ] CREATED COPY WITH SAME PERMISSIONS ON %s",newPath,newDest);
					mkdir(newDest,stare.st_mode);
					chmod(newDest,stare.st_mode);		
				}
			
			if(S_ISREG(stare.st_mode))
			{
				if(stare.st_size >= 500 )
					{
						ReadWriteFiles(newPath,newDest);
						chmod(newDest,stare.st_mode|S_IWGRP+S_IWOTH+S_IWUSR);
					}
				else if(stare.st_size < 500 && stare.st_size >=300)
					{
						link(newPath,newDest);
						chmod(newDest,stare.st_mode);
						printf("\n [\033[0m [ + ] FOUND %s FILE WITH MORE THAN 300 BUT LESS THAN 500 BYTES\n \033[32m[ + ] CREATED HARD LINK WITH SAME PERMISSIONS ON  %s \n", newPath,newDest);

					}
				else if(stare.st_size < 300)
					{
						symlink(newPath,newDest);
						chmod(newDest,stare.st_mode);
						printf("\n\033[0m [ + ] FOUND %s FILE WITH LESS THAN 500 BYTES\n\033[32m [ + ] CREATING SYMBOLIC LINK WITH SAME PERSMISSIONS ON %s \n",newPath,newDest);
					
					}	

			}

                        
                        list(newPath,newDest);

			
		}
        }
    }

void ReadWriteFiles(char *source, char *dest)
{
	printf("\n\033[0m [ + ] FOUND %s FILE BIGGER THAN 500 BYTES \n\033[32m [ + ] CREATING COPY WITH WRITE PERMISSIONS FOR EVERY USER ON %s \n",source,dest); 
	int r=open(source, O_RDONLY);
	int w=creat(dest, S_IREAD|S_IWRITE);
	int cititi;
	char buffer[1000];
	while(cititi=read(r, &buffer, 4))
	{
		buffer[cititi]="\0";
		write(w,buffer,4);
	}
	close(r);
	close(w);
	
}
