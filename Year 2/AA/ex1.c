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
int BinarySearch(int* arr, unsigned short n)
{
	printf("intra");
		//get a random number from the array so we can search for it
	unsigned short nr =*(arr+rand()%n);
	printf("intra");
	unsigned short low=0,high=n-1,mid;
	printf("intra");
	int res=-1;
	printf("intra");
	while(high-low > 1)
	{
		mid=low-(high-low)/2;
		printf("NR ESTE :%d",*(arr+mid));
		if(*(arr+mid)<nr)
			low=mid+1;
		else if(*(arr+mid)>nr)
			high=mid-1;
		else
			return *(arr+mid);
	}
//	printf("\n%d\n",res);
	return -1;
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

void Display(unsigned short n, int* arr)
{
	unsigned short i;
	for(i=0;i<n;i++)
                printf("[%d] ", *(arr+i));
	printf("\n");
}

void PopulateArray(unsigned short n)
{
	unsigned short i;
	int* arr;
	arr=(int*)malloc(n*sizeof(int));
        srand(time(NULL));
        for(i=0;i<n;i++)
                *(arr+i)=rand()%1000;
}
void Run(){
	printf("intra");
	unsigned short n=GetSize(),i;
	int* arr;
	PopulateArray(n);
	Display(n,arr);
	QuickSort(arr,0,n-1);
	Display(n,arr);
	//BinarySearch(arr,n);
}
int main()
{
	Run();
}
