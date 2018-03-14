//program to delete all nodes from linked list
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **headref,int data)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=*headref;
	*headref=new_node;
}
void printlist(struct node *n)
{
	while(n!=NULL)
	{
		printf("%d",n->data);
		n=n->next;
	}
}
// function to delete elements of linked list 
void delete(struct node **head)
{	
	/* deref head_ref to get the real head */
	struct node *curr=*head;
	struct node *next;
	while(curr!=NULL)
	{
		next=curr->next;
		free(curr);
		curr=next;
	}
	/* deref head_ref to affect the real head back
      in the caller. */
	*head=NULL;
		 
}
// Driver function
int main()
{
	struct node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	printf("the linked list is as follows\n");
	printlist(head);
	delete(&head);
	printf("Empty list");
	printlist(head);
	return 0;	
}
