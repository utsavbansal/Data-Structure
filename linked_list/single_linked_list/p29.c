// program to delete duplicates from sorted linked list
#include<stdio.h>
#include<stdlib.h>

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

// function to remove duplicatea
void removedup(struct node *headref)
{
	struct node *current=headref,*next_next;
	while(current->next!=NULL)
	{
		if(current->data==current->next->data)
		{
			next_next=current->next->next;
			free(current->next);
			current->next=next_next;
			
		}
		else
		current=current->next;
	}
	

}


int main()
{
	struct node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,5);
	printf("the linked list is as follows\n");
	printlist(head);
	printf("after removing duplicates \n");
	removedup(head);
	printlist(head);
	return 0;	
}

