#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int* a, int*b)
{
	int t = *a;
	*a = *b;
	*b=t;
}
int partition(int* arr, int low, int high)
{
	int pivot=*(arr+high);
	int j, i= low-1;
	for(j=low;j<high;j++)
		if(*(arr+j) < pivot)
		{
			i++;
			Swap((arr+i),(arr+j));
		}
	Swap((arr+i+1),(arr+j));
	return i+1;	
}
void QuickSort(int*arr, int low, int high)
{
	if(low<high)
	{
		int index = partition(arr, low, high);
		QuickSort(arr, low, index-1);
		QuickSort(arr, index+1, high);
	}	
}
int BinarySearch(int* arr, unsigned short n,int nr)
{
	int i=1;
	int low=0,high=n-1;
	int mid=(high+low)/2;
	while(high!=low)
	{
		if(*(arr+mid)<nr)
			low=mid+1;
		else if(*(arr+mid)>nr)
			high=mid-1;
		else
		{
			printf("[BINARY SEARCH]:Numarul %d a fost gasit dupa %d iteratii pe pozitia ", nr,i);
			return mid;
		}
		mid=(high+low)/2;
		i++;
	}
		
	
	return mid;
}
unsigned short GetSize(){
	unsigned short n;
	do
	{
		printf("Introduceti numarul de elemente aleatoare\n");
		scanf("%hu",&n);
	}while(n>100 || n<2);

	return n;
}
int LinearSearch(int* arr, int n, int nr)
{
	unsigned short i,j=1;
	for(i=0;i<n;i++)
	{
		if(*(arr+i) == nr)
		{
			printf("[LINEAR SEARCH]:Numarul %d a fost gasit dupa %d iteratii pe pozitia",nr,j);
			return i;
		}
		j++;
	}
	return -1;
}
void Display(unsigned short n, int* arr)
{
	unsigned short i;
	for(i=0;i<n;i++)
                printf("[%d] ", *(arr+i));
	printf("\n");
}

int* PopulateArray(unsigned short n)
{
	unsigned short i,j,flag_end=1;
	int nr;
	int* arr=(int*)malloc(n*sizeof(int));
        srand(time(NULL));
        for(i=0;i<n;i++)
	{
		flag_end=1;
		while(flag_end)
		{
			flag_end=0;
			nr=rand()%1000;
			for(j=0;j<i;j++)
				if(*(arr+j) == nr)
					flag_end=1;
				if(!flag_end)
				{
					*(arr+i)=nr;
					break;
				}

		}
	}
	return arr;
}


void Run(){
	unsigned short n=GetSize(),i;
	int* arr=PopulateArray(n);
	int nr =*(arr+rand()%n);
	printf("\nSe cauta numarul %d\n",nr);
	Display(n,arr);
	printf(" %d\n",LinearSearch(arr,n,nr));
	QuickSort(arr,0,n-1);
	printf("%d\n",BinarySearch(arr,n,nr));

}

int main()
{
	Run();
}

