//Linked List Traversal
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
//function to print list 
void printlist(struct Node* n)
{
	while(n!=NULL)
	{
		printf("%d",n->data);
		n=n->next;
	}
}
//main method
int main()
{
	struct Node *head=NULL,*second=NULL,*third=NULL;
	head=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	
	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;
	// call the function
	printlist(head);
	return 0;
}

