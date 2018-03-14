//program to get nth node from linked list
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
// function to get nth element of linked list
int getelement(struct node *head,int index)
{
	int count=0;
	while(head!=NULL)
	{
		if(count==index)
			return(head->data);
		count++;
		head=head->next;
	}
	/* if we get to this line, the caller was asking
       	for a non-existent element so we assert fail */
    	assert(0);   
}
// Driver function
int main()
{
	int index,element;
	struct node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	printf("the linked list is as follows\n");
	printlist(head);
	printf("\nEnter the index to get the element\n");
	scanf("%d",&index);
	element=getelement(head,index);
	printf("\nthe element is %d ",element);
	return 0;	
}
