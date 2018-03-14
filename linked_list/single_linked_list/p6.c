// program to delete key from linked list
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
		printf("%d",n->data);
		n=n->next;
	}
}

// function to delete the key
void delete(struct node** headref,int key)
{
	// Store head node
	struct node *temp=*headref,*prev;
	// if head node itself holds the key to be deleted
	if(temp!=NULL && temp->data==key)
	{
		*headref=temp->next;
		return ;
	}
	// Search for the key to be deleted, keep track of the
    	// previous node as we need to change 'prev->next'
	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	//if key was not present in linked list
	if(temp==NULL)
		return ;
	prev->next=temp->next;
	free(temp);
}

int main()
{
	int key;
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
	printf("Before deletion linked list is as follows\n");
	printlist(head);
	printf("\nEnter the data to be deleted\n");
	scanf("%d",&key);
	// call the delete function
	delete(&head,key);
	printlist(head);
	return 0;
}
