// insert the node  At the end of the linked list
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
// function to creat node at  end
void append(struct node** headref,int new_data)
{
	struct node *new_node;
	// Allocate node
	new_node=(struct node*)malloc(sizeof(struct node));
	// Allocate data
	new_node->data=new_data;
	struct node *last=*headref;
	// if list has no value
	if(*headref==NULL)
	{
		*headref=new_node;
		return ;
	}
	// to append at last first traverse the list
	while(last->next!=NULL)
		last=last->next;
	// append the the new node
	last->next=new_node;
	return;
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
	// call the append function
	append(&head,new_data);
	printlist(head);
	return 0;
}
