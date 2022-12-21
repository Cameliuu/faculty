#include<stdio.h>
#include<stdlib.h> 	
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/wait.h>

void handler(int sig)
{
	signal(SIGUSR1,handler);
	switch(sig)
	{
		case SIGUSR1:
			printf("\n[ + ] SENT USER DEFINED SIGNAL");
			break;
	}
}

void main()
{
	int d[2];
	int i;
	signal(SIGUSR1,handler);
	int pid = fork();
	if(pid==0)
	{		
		int status;
			printf("CHild process working");
			sleep(1);
		kill(SIGUSR1,pid);
		wait(&status);		
	}
	else
	{
		
			printf("working");
			sleep(1);

			
			
	}

}

