#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/wait.h>

void handler(int sig)
{
	printf("BINGO!\n");
	(void)signal(SIGUSR1,handler);
}
void main()
{
	int pid;

	pid = fork();
	if(pid)
	{
			int status;
			sleep(5);
			//functia kill transmite procesului cu pid egal cu primul parametru, semnalul dat ca al doilea parametru
			kill(pid, SIGUSR1);
			/wait(&status);			
	}
	else
	{
		(void)signal(SIGUSR1,handler);	
		int k = 1;
		while(k<=10)
		{
			sleep(1);	
			printf("%d Child process working...\n", k);		
			k++;
		}
	}
	
}
