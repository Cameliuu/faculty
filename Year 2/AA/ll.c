#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
}node;

void printlist(node *head)
{
	node *temp = head;
	while(temp != NULL)
	{
		printf("%d - ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}
int main()
{
	node n1,n2,n3;
	node* head;
	n1.val=5;
	n2.val=6;
	n3.val=7;

	head=&n3;
	n3.next=&n2;
	n2.next=&n1;
	n1.next=NULL;

	printlist(head);
}
