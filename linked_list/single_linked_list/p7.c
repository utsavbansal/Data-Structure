// program to delete a node at given position in linked list
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

// function to delete a node at given position 
void delete(struct node** headref,int pos)
{
	// if linked list is empty
	if(*headref==NULL)
		return ;
	// store the node
	struct node *temp=*headref;
	//if heads need to be removed
	if(pos==0)
	{
		*headref=temp->next;
		free(temp);
		return;
	}
	//find previous node of node to be deleted
	for(int i=0;temp!=NULL && i<pos-1;i++)
		temp=temp->next;
	// if pos more than number of nodes
	if(temp==NULL || temp->next==NULL)
		return;
	// Node temp->next is the node to be deleted
	// Store pointer to the next of node to be deleted
	struct node *next = temp->next->next;
 	// Unlink the node from linked list
    	free(temp->next);  // Free memory
 
    	temp->next = next;  // Unlink the deleted node from list
}
int main()
{
	int pos;
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
	printf("\nEnter the pos to be deleted\n");
	scanf("%d",&pos);
	// call the delete function
	delete(&head,pos);
	printlist(head);
	return 0;
}
