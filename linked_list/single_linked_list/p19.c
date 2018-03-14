//Write a function that counts the number of times a given int occurs in a Linked List
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
// function to search occurences of given element in linked list 
int search(struct node *head,int key)
{	
	int count=0;
	while(head!=NULL)
	{
		if(head->data==key)
			count++;
		head=head->next;
	}
	return count;
		 
}
// Driver function
int main()
{
	int key,occur;
	struct node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,1);
	printf("the linked list is as follows\n");
	printlist(head);
	printf("Enter the element you want to search\n");
	scanf("%d",&key);
	occur=search(head,key);
	printf("%d",occur);
	return 0;	
}
