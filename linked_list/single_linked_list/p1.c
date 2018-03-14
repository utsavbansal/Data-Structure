//First Simple Linked List in C Let us create a simple linked list with 3 nodes.

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};
int main()
{
	//Initialise
	struct Node* head=NULL;
	struct Node* second=NULL;
	struct Node* third=NULL;
	//Allocate memory
	head=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	// Assign values
	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;
	return 0;
}
