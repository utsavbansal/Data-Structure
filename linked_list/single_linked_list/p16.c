//program to get nth node from last of linked list 
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
void getnthelement(struct node *head,int index)
{	
	int len=0,i;
	struct node *temp=head;
	// 1) count the number of nodes in Linked List
	while(head!=NULL)
	{
		len++;
		head=head->next;
	}
	// check if value of n is not more than length of the linked list
	if(len<index)
		return ;
	// 2) get the (n-len+1)th node from the begining
	for(i=1;i<len-index+1;i++)
		temp=temp->next;
	printf("the nth element is %d",temp->data); 
}
// Driver function
int main()
{
	int index;
	struct node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	printf("the linked list is as follows\n");
	printlist(head);
	printf("Enter the nth index\n");
	scanf("%d",&index);
	getnthelement(head,index);
	return 0;	
}
