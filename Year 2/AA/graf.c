#include<stdio.h>
#include<stdlib.h>
#define N 7

typedef struct  graf
{
	int mat[N][N];
	int noduri[N];
	int vizitat[N];
	int freeslot;
	short in;
}GRAF;

int posMin(GRAF* graf,int nod)
{
	int i,min = graf->mat[0][0];
	for(i=0;i<N;i++)
	{
			
	}
}
int init(GRAF *graf)
{
	if(graf->in)
	{
		printf("[ ! ] GRAFUL ESTE DEJA INITIALIZAT!");
		return -1;
	}
	int i,j;
	graf->freeslot=0;
	for(i=1;i<=N;i++)
	{
		graf->noduri[i]=-1;
		graf->vizitat[i]=0;
		for(j=1;j<=N;j++)
		{
			graf->mat[i][j]=-1;
		}
	}
	graf->in=1;
	printf("\n[ + ] GRAFUL A FOST INITIALIZAT\n");
	return 1;	
}
int isValid(int u, int v, GRAF *graf)
{
	if (u == v)
        return 0;
    if (graf->vizitat[u] == 0 && graf->vizitat[v] == 0)
        return 0;
    else if (graf->vizitat[u] == 1 &&
             graf->vizitat[v] == 1)
        return 0;
    return 1;
}
void prim(GRAF *graf, int nod)
{

	int count=0,mincost=0,min =999,u=-1,v=-1,i,j;
	graf->vizitat[nod]=1;
	while(count < N-1)
	{
		u=-1;
		v=-1;
		min=999;	
		for(i=nod;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(graf->mat[i][j] < min && graf->mat[i][j]!=-1)
				{
					if(isValid(i,j,graf))
					{
						min = graf->mat[i][j];
						u=i;
						v=j;
					}	
				}
					
			}
		}
		if(u!=-1 && v!=-1)
		{
			printf(" EDGE %d :  {%d} : {%d}, cost = %d\n",count++,u,v,min);
			mincost+=min;
			nod = 0;
			graf->vizitat[u]=graf->vizitat[v]=1;
		}
	}

	printf("\nCost total: %d",mincost);
	
}
void test(GRAF *graf)
{
	graf->in=1;
		int test[7][7]={
			{-1,2,5,-1,-1,7,8},
			{2,-1,-1,-1,-1,-1,-1},
			{5,-1,-1,-1,-1,-1,-1},
			{-1,-1,-1,-1,3,5,-1},
			{-1,-1,-1,3,-1,4,6},
			{7,-1,-1,5,4,-1,-1},
			{8,-1,-1,-1,6,-1,-1}
		};
		int i,j;
		printf("\n");
		for(i=0;i<7;i++)
		{
			for(j=0;j<7;j++)
			{
				graf->mat[i][j] = test[i][j];
				printf("%d ", test[i][j]);
			}
		printf("\n");
		}
}
void introducere_nod(GRAF *graf)
{
	if(!graf->in)
	{
		printf(" [ ! ] GRAFUL NU ESTE INITAILIZAT!");
		return -1;
	}
	int val;
	printf("\nIntroduceti valoarea: ");
	scanf("%d", &val);
	graf->noduri[val] = 1;
	(graf->freeslot)++;
	return 1;
}
void introducere_arc(GRAF *graf)
{
	int n1,n2,pondere;
 	if(!graf->in)
        {
                printf(" [ ! ] GRAFUL NU ESTE INITAILIZAT!");
                return -1;
        }
	printf("Introduceti primul nod ");
	scanf("%d",&n1);
	printf("Introduceti al doilea nod: ");
	scanf("%d",&n2);
	printf("Introduceti ponderea arcului: ");
	scanf("%d",&pondere);
	if(graf->noduri[n1]==-1 || graf->noduri[n2]==-1)
	{
		printf("[ ! ] UNUL DINTRE NODURI NU EXISTA!");
		return -1;	
	}	
	graf->mat[n1][n2]=pondere;
	graf->mat[n2][n1]=pondere;
	return 1;
}
void stergere_nod(GRAF *graf)
{
	 int n1,i,j;
	 if(!graf->in)
         {
                printf(" [ ! ] GRAFUL NU ESTE INITAILIZAT!");
                return -1;
         }
	 printf("Introduceti nodul de sters: ");
	 scanf("%d", &n1);
	 graf->noduri[n1]=-1;
	 for(i=1;i<=N;i++)
		 for(j=1;j<=N;j++)
			 if(i==n1)
			 {
			 	graf->mat[i][j] = -1;
					graf->mat[j][i] = -1;
			 }
	 return -1;
	

}
void DFST(GRAF *graf, int x)
{

	int i;
	graf->vizitat[x]=1;
	printf("[%d] ",x);
	for(i=1;i<=N;i++)
	{
		if(graf->mat[x][i]!=-1)
			{
				if(!graf->vizitat[i])
					DFST(graf, i);
			}
	}
}

void ReInitVisited(GRAF *graf)
{
	int i;
	for(i=0;i<N;i++)
		graf->vizitat[i]=0;
}
void stergere_arc(GRAF *graf)
{
	int n1,n2;
	if(!graf->in)
        {
                printf(" [ ! ] GRAFUL NU ESTE INITAILIZAT!");
                return -1;
        }
	printf("[ + ] INTRODUCETI PRIMUL NOD: ");
	scanf("%d",&n1);
	printf("[ + ] INTRODUCETI AL DOILEA NOD: ");
	scanf("%d",&n2);
	graf->mat[n1][n2]=-1;
	graf->mat[n2][n1]=-1;
	return 1;

}
void afisare(GRAF *graf)
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf(" %d ", graf->mat[i][j]);
		printf("\n");
	}		

}
int getStartNode(GRAF *graf)
{
	int ans;
	do
	{
		printf("[ + ] INTRODUCETI NODUL DE INCEPUT!: ");
		scanf("%d" , &ans);
	}while(ans<0 || ans>N || graf->noduri[ans]==-1);
	return ans;
}
void main()
{
	GRAF graf;
	graf.in=0;
	int ans,primN;
	while(1)
	{
		printf("\n--------------------------------INTRODUCETI OPTIUNEA-----------------------------------");
		printf("\n0.Iesire\n1.Initializare\n2.Introducere nod\n3.Introducere arc\n4.Afisare matrice\n5.Stergere nod\n6.Stergere arc\n7.Traversare in adancime\n8.Prim");
		scanf("%d",&ans);
		switch(ans)
		{
			case 0:
				exit(0);
				break;
			case 1:
				init(&graf);
				test(&graf);
				break;
			case 2:
				introducere_nod(&graf);
				break;
			case 3:
				introducere_arc(&graf);
				break;
			case 4:
				afisare(&graf);
				break;
			case 5:
				stergere_nod(&graf);
				break;
			case 7:
				DFST(&graf,getStartNode(&graf));
				ReInitVisited(&graf);
				break;
			case 8:
				printf("Introduceti nodul de inceput: ");
				scanf("%d",&primN);
				printf("\n%d\n",primN);
				prim(&graf,primN);
				ReInitVisited(&graf);
				break;
			default:
				printf("\nOPTIUNE GRESITA!\n");
					
		}
	}

}
