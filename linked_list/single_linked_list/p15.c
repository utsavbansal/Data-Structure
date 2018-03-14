//program to get middle node from linked list using two pointers
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
// function to get mid element of linked list using two ptr
void getelement(struct node *head)
{	
	struct node *fast_ptr=head;
	struct node *slow_ptr=head;
	while(head!=NULL)
	{
		if(fast_ptr!=NULL&&fast_ptr->next!=NULL)
		{
			fast_ptr=fast_ptr->next->next;
			slow_ptr=slow_ptr->next;
		}
		head=head->next;
	}
	printf("the mid element is %d",slow_ptr->data); 
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
	getelement(head);
	return 0;	
}
