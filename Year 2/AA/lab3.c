#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
int A[MAX];
char K[MAX];
int freeslot=0;
int FD[MAX];
int PF[MAX];
int Insert(char c, int tata)
{
	unsigned short i;
		if(!freeslot)
		{
			A[freeslot]=freeslot;
			K[freeslot]=c;
			freeslot++;
			return 1;
		}
			A[freeslot]=tata;
			if(PF[tata-1] == -1)
				PF[tata-1] = freeslot;
			if(A[freeslot-1] == tata)
				FD[freeslot-1]=freeslot;
			K[freeslot]=c;
			printf("Nodul %c a fost inserat pe pozitia %d\n",c,freeslot);			
			freeslot++;
			return 1;
}
int PreOrdine(int i)
{
		printf("\nPozitie: %hu\nValoare: %c\n ,Tata: %d\nPrim fiu: %d\n Frate dreapta:%d \n",i,K[i],A[i],PF[i],FD[i]);
	       	if(PF[i] != -1)
			{
				PreOrdine(PF[i]);
			}
		else if(PF[i] == -1 && FD[i] != -1)
			PreOrdine(FD[i]);
		else
			return 0;
	return 0;

}
int PostOrdine(int i)
{
	if(PF[i]!=-1)
		PostOrdine(PF[i]);
	printf("[%c] ",K[i]);
	if(FD[i]!=-1)
		PostOrdine(FD[i]);	
              

        return 0;



}
int InOrdine(int i)
{
	unsigned short j;
	if(PF[i] == -1)
		printf("%c", K[i]);
	else
		{
			InOrdine(PF[i]);
			printf("%c", K[i]);
			for(j=i+1;j<=freeslot;j++)
			{
				if(A[j]==i+1 && j != PF[i])
					InOrdine(j);
			}
		}
        return 0;


}
void Delete(char c)
{
	printf("Intra pe delete");
	unsigned short i,j;
	for(i=0;i<MAX;i++)
	{
		if(K[i]==c)
		{
			printf("\nCheia %c a fost stearsa %hu\n",c,i);
			K[i] = 0;
			A[i] = -1;
			PF[i] = -1;
			FD[i-1]= -1;						
			freeslot--;
			for(j=0;j<MAX;j++)
				if(A[j]==i+1)
					Delete(K[j]);
		}
	}
}
void InsertTest()
{
	Insert('r',0);
	Insert('c',1);
	Insert('b',1);
	Insert('e',3);
	Insert('a',3);
	Insert('f',3);
}
void Display()
{
	unsigned short i;
	printf("\n Vectori Tati\n");
	printf("%d ",A[0]);
	for(i=1;i<10;i++)
        {
                printf("%d ",A[i]);
        }
	printf("\nVector Chei\n");
	for(i=0;i<MAX;i++)
        {
                printf("%c ",K[i]);
        }
	printf("\nVector Prim Fiu\n");
        for(i=0;i<MAX;i++)
        {
                printf("%d ",PF[i]);
        }
	printf("\nVector Frate Dreapta\n");
        for(i=0;i<MAX;i++)
        {
                printf("%d ",FD[i]);
        }

	printf("\n");


}
void Init()
{
	unsigned short i;
	for(i=0;i<MAX;i++)
	{
		A[i]=-1;
		FD[i] = -1;
		PF[i]=-1;
		K[i]=-1;
	}
}
int Run()
{
	int opt,t;
	char c;
	while(1)
	{
		printf("Alegeti optiunea\n0.Iesire\n1.Inserare\n2.Stergere\n3.Afisare\n4.Afisare preordine\n5.Afisare Postordine\n6.Afisare Inordine\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				return -1;
			case 1:
				/*printf("Introduceti valoare cheii: ");
				getchar();
				scanf("%c",&c);
				printf("Introduceti valorea tatalui: ");
				scanf("%d",&t);
				Insert(c,t);*/
				InsertTest();
				break;
			case 2:
				printf("Introduceti cheia de sters: ");
				getchar();
				scanf("%c",&c);
				Delete(c);
				break;
			case 3:
				Display();
				break;
			case 4:
				PreOrdine(0);
				break;
			case 5:
				PostOrdine(0);
				break;
			case 6:
				InOrdine(0);
				break;
		}



	}
}
int main()
{
	Init();
        Run();
}

