#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define N 100
void creeare(int arr[])

{

	int i,j,flag_end,nr;

	srand(time(NULL));

	for(i=0;i<N;i++){

	flag_end=1;

	while(flag_end){

		flag_end=0;

		nr=rand()%1000;

		for(j=0;j<N;j++)

			if(arr[j]==nr) flag_end=1;

	if(!flag_end){

		arr[i]=nr;

		break;

	}

	}

	}

}
void sort(int arr[])
{
	int i,ok=0,aux;
	do{
		ok=0;
		for(i=0;i<N-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				ok=1;
				aux=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=aux;
			}
		}

	}while(ok==1);
}
int binara(int arr[], int nr)
{
	int i=1;
	int low=0,high=N-1;
	int mid=(high+low)/2;
	while(low<=high)
	{
		printf("[%d] %d [%d] \n",low,arr[mid],high);
		if(arr[mid]<nr)
			low=mid+1;
		else if(arr[mid]>nr)
			high=mid-1;
		else if(arr[mid]==nr)
			return i;
		
		mid=(high+low)/2;
		i++;
	}


	return -1;
}

int liniara(int arr[],int nr)
{

	int i,n=0;
	for(i=0;i<N;i++)
	{
		n++;
		if(arr[i]==nr)
			return n;
	}
}
void print(int arr[])
{
	int i;
	for(i=0;i<N;i++)
		printf("[%d] ",arr[i]);
       printf("\n");	
}
int main()
{
	int v[N],nr;
	creeare(v);
	print(v);
	sort(v);
	print(v);
	printf("Introduceti numarul pe care doriti sa l cautati: ");
	scanf("%d",&nr);
	printf("\n[CAUTARE LINIARA] Numarul %d a fost gasit dupa %d iteratii\n",nr,liniara(v,nr));
	printf("\n[CAUTARE BINARA] Numarul %d a fost gasit dupa %d iteratii",nr,binara(v,nr));
}
