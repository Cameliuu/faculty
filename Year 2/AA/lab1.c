#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	int arr[100],i,aux;
	unsigned short ok;
	srand(time(NULL));
	for(i=0;i<100;i++)
		arr[i]=rand()%1000;
	do
	{
		ok=0;
		for(int i=0;i<99;i++)
		{
			if(a[i] > a[i]+1)
			{
				aux=a[i];
				a[i]=a[i+1];
				a[i+1] = aux;
			}
		}

	}
	for(i=0;i<100;i++)
                printf("[%d] ",arr[i]);
        printf("\n");

	return 0;
}
