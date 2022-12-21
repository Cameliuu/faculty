#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/*
Se considera un program C ce contine doua procese (parinte + fiu). Procesul parinte va
trimite, printr-un pipe, timp de 5s caracterul “a” catre procesul fiu, în plus la fiecare
secunda o sa trimita semnalul SIGUSR1. Procesul fiu va citi caracterele din pipe si va
realiza o statistica ce va contine numarul total de caractere, precum si numarul de
caractere primite dupa fiecare semnal SIGUSR1. La final statistica va fi trimisa printr-un
pipe procesului parinte ce o va afisa.
*/

unsigned long total = 0, curent = 0, pas[5], poz = 0, secunde = 0;
//pfd - pipe folosit pentru transmiterea datelor ( caracterului a)
//pfst - pipe folosit pentru transmiterea statisticilor
int pfd[2],pfst[2];
pid_t fiu;


//functie care anunta ca s-a transmis semnalul SIGUSR1
void stat()
{

	printf("Procesul fiu a primit semnalul SIGUSR1.\n");

	//numarul de caractere transmise la pasul curent
	pas[poz] = curent;

	//pozitia curenta
	poz++;

	//total de caractere transmise
	total+=curent;

	curent=0;

}

//functie care transmite statisticile in pipe-ul de statistici
void finalfiu()
{
	int i;

	//scriem din total in pipe-ul de statistici
	write(pfst[1], &total, sizeof(unsigned long));

	for (i = 0; i < 5; i++){
        //scriem din pas[i] in pipe-ul de statistici nr de caractere la pasul i
		write(pfst[1], &pas[i], sizeof(unsigned long));
	}

	//inchidem descriptorul de output a pipe-ului de statistici
	close(pfst[1]);

	exit(0);
}

//functie care dupa 5 secunde va afisa statisticile
void alarma()
{
    	int i=0;

	//daca au trecut 5 secunde
	if (secunde == 5)
	{
		//terminam procesul fiu si transmitem semnalul SIGUSR2
		kill(fiu, SIGUSR2);

		//citim din pipe-ul de statistici in total
		read(pfst[0], &total, sizeof(unsigned long));

		printf("Procesul fiu a terminat de executat.\nStatistica:\n");

		//citim din pipe-ul de statistici in pas[i] numarul de caractere transmise la pasul i cat timp este de citit
		while (read(pfst[0], &pas[i], sizeof(unsigned long)) > 0)
		{
			printf("Numarul de caractere trimise la pasul %d : %ld\n",i+1, pas[i]);
			i++;
		}

		printf("Numarul total de caractere trimise      : %ld\n", total);

		//inchidem descriptorul de input a pipe-ului de statistici
		close(pfst[0]);
		exit(0);

	}
	else
	{
	    	//daca nu s-au atins cele 5 secunde incheiem procesul fiu si transmitem semnalul SIGUSR1
		kill(fiu, SIGUSR1);
		secunde++;

		//asteptam 1 secunda
		alarm(1);
	}
}

int main()
{
	char buffer;
	int i;

    	//identificam eroare la pipe-ul de date
	if (pipe(pfd) < 0)
    	{
		perror("Eroare la pipe-ul de date!\n");
		exit(1);
	}

	//identificam eroare la pipe-ul de statistici
	if (pipe(pfst) < 0)
    	{
		perror("Eroare la pipe-ul de statistici!\n");
		exit(1);
	}

	//testam daca s-a realizat fork-ul
	if ((fiu = fork()) < 0)
    	{
		perror("Eroare la fork!\n");
		exit(2);
	}

	//daca suntem in procesul fiu
	if (fiu == 0)
	{
	    	//inchidem descriptorul de output a pipe-ului de date
		close(pfd[1]);

		//inchidem descriptorul de output a pipe-ului de statistici
		close(pfst[0]);
		
		
        	//la intalnirea semnalului SIGUSR1 in proces se va apela rutina stat
		signal(SIGUSR1, stat);
        
        	//la intalnirea semnalului SIGUSR2 in proces se va apela rutina finalfiu
		signal(SIGUSR2, finalfiu);


        	//citim cate caractere s-au transmis
		while(read(pfd[0], &buffer, 1) > 0)
			curent++;
        
        
        	//inchidem descriptorul de input a pipe-ului de date
		close(pfd[0]);
		
		//inchidem descriptorul de input a pipe-ului de statistici
		close(pfst[0]);
		
		exit(0);
	}
	
	//daca suntem in procesul parinte
	else
    	{
        	//inchidem descriptorul de input a pipe-ului de date
		close(pfd[0]);
		
		//inchidem descriptorul de output a pipe-ului de statistici
		close(pfst[1]);
		
        
        	//la intalnirea semnalului SIGALRM(produs de alarm(1) ) se va apela rutina alarma
		signal(SIGALRM, alarma);


        	//asteptam o secunda
		alarm(1);


        	//se transmite caracterul a in pipe pana cand va fi intrerupt de un semnal
		while(1)
			write(pfd[1], "a", 1);
        
        
        	//inchidem descriptorul de input a pipe-ului de date
		close(pfd[0]);
		
		//inchidem descriptorul de output a pipe-ului de statistici
		close(pfst[1]);
	}

	return 0;
}

