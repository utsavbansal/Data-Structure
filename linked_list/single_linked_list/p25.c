/*
Given only a pointer/reference to a node to be deleted in a singly linked list, how do you delete it?

Given a pointer to a node to be deleted, delete the node. Note that we don’t have pointer to head node.*/
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
// function to delete element of linked list 
void delete(struct node *node_ptr)
{	
	struct node *temp=node_ptr->next;
	node_ptr->data=temp->data;
	node_ptr->next=temp->next;
	free(temp);	 
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
	printf("Before deleting \n");
    printlist(head);
 
    /* I m deleting the head itself.
        You can check for more cases */
    delete(head);
 
    printf("\nAfter deleting \n");
    printlist(head);
    getchar(); 
    return 0;
}
