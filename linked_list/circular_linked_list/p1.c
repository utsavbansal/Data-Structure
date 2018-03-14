/* Function to traverse a given Circular linked list and print nodes */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

// function to push elements in list
void push(struct node **head,int data)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	struct node *tmp=*head;
	new_node->data=data;
	new_node->next=*head;
	if(*head!=NULL){//if linked list is not null the set the next of last node
		while(tmp->next!=*head)
			tmp=tmp->next;
		tmp->next=new_node;
	}
	else
		new_node->next=new_node;// for first node
	*head=new_node;	
}
// function to print list
void printlist(struct node *head)
{
	struct node *tmp=head;
	// If linked list is not empty
	if(head!=NULL)
	{
		do
		{
			printf("%d",tmp->data);
			tmp=tmp->next;
		}while(tmp!=head);
	}

	
}
// main method
int main()
{
	struct node *head=NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	push(&head,0);
	printlist(head);
	return 0;
}
