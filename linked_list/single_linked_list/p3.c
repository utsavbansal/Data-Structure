// insert the node  At the front of the linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void printlist(struct node* n)
{
	while(n!=NULL)
	{
		printf("%d ",n->data);
		n=n->next;
	}
}
// function to creat node at front end
void push(struct node** headref,int new_data)
{
	struct node *new_node;
	// Allocate node
	new_node=(struct node*)malloc(sizeof(struct node));
	// Allocate data
	new_node->data=new_data;
	// make next of new node as head
	new_node->next=(*headref);
	// move the head to point to the new node
	(*headref)=new_node;
}
int main()
{
	int new_data;
	struct node** headref;
	struct node *head=NULL,*second=NULL,*third=NULL;
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;
	printf("Before insertion linked list is as follows\n");
	printlist(head);
	printf("\nEnter the data to be inserted\n");
	scanf("%d",&new_data);
	// call the push function
	push(&head,new_data);
	printlist(head);
	return 0;
}
