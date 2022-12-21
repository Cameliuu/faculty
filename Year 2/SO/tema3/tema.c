#include<stdio.h>
#include<stdlib.h> 
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/wait.h>
unsigned long total = 0, count = 0, sec[7], poz = 0, secunde = 0;
int d[2];
int s[2];
int nr;
pid_t f;
void handler(int sig)
{
	switch (sig)
	{
		case SIGUSR1:
			printf("\n[ + ] SENT USER DEFINED SIGNAL(SIGUSR1)");
			printf("[%lu]",count);
	        	sec[poz]=count;
			poz++;
			total += count;
			count = 0;	
			break;
		case SIGUSR2:
		printf("\n[ + ] SENT USER DEFINED SIGNAL(SIGUSR2)");
			int i;
			close(d[0]);
			write(s[1], &total, sizeof(unsigned long));
			for(i=0;i<7;i++)
			{
				 write(s[1], &sec[i], sizeof(unsigned long));
			}
			close(s[1]);
			exit(0);
			break;
		case SIGALRM:
			int j=0;
			if(secunde == 7)
			{
				close(d[1]);
				kill(f, SIGUSR2);
				read(s[0],&total,sizeof(unsigned long));
				printf("\n [ + ] CHILD PROCESS FINISHED EXECUTION\n[ + ]STATISTICS:\n");
				while (read(s[0], &sec[j], sizeof(unsigned long)) > 0)
				{
					printf("[ + ] NUMBER OF 'E' CHARACTERS SENT AT %d SECOND : %ld\n",j+1, sec[j]);
					j++;
				}
				printf("[ + ] NUMBER OF TOTAL 'E' CHARACTERS SENT : %ld\n",total);
				close(s[0]);
				exit(0);	
			}
			else
			{
				kill(f,SIGUSR1);
				secunde++;
				alarm(1);
			}
			break;

	}
}
	

int main()
{
	char a1 = 'e';
	if(pipe(d) == -1)
	{
		printf("\n[ ! ] AN ERROR HAS OCCURED WHILE OPENING THE FIRST PIPE[DATA]!");
		exit(0);	
	}
	if(pipe(s) == -1)
	{
		printf("\n[ ! ] AN ERROR HAS OCCURED WHILE OPENING THE SECOND PIPE[STATISTICS]!");
		exit(0);
	}
	if((f = fork())<0)
	{
		printf("\n[ ! ] AN ERROR HAS OCCURED WHILE TRYING TO FORK");
		exit(0);
	}
	if(f==0)
	{
		close(d[1]);


		close(s[0]);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		while(1)
		{
			nr=read(d[0],&a1,sizeof(char));
			count++;
		}		
		close(d[0]);
		close(s[0]);
		exit(0);		
	}
	else
	{
		close(d[0]);
		close(s[1]);
		signal(SIGALRM, handler);
		alarm(1);
		while(1)
			write(d[1],&a1,1);
		close(d[0]);
		close(s[1]);

	}
}
