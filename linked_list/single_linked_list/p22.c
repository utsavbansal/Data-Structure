// program to merge two sorted linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int new_data)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=*head;
	*head=new_node;
}
void printlist(struct node *n)
{
	while(n!=NULL)
	{
		printf("%d",n->data);
		n=n->next;
	}
}
// function to sort the list
struct node* sorted_merge(struct node *a,struct node *b)
{
	// if one list is null then just return the other one 
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	//case to get first node is slightly different from the body of while loop
	struct node *head;
	if(a->data < b->data)
	{
		head=a;
		a=a->next;
	}
	else if(b->data < a->data)
	{
		head=b;
		b=b->next;
	}
	head->next=NULL;
	struct node *curr=head;
	// compare the first element of each list for every iteration and pick the smaller element to get the result
	while(a!=NULL && b!=NULL)
	{
		if(a->data < b->data)
		{
			curr->next=a;
			a=a->next;
		}
		else
		{
			curr->next=b;
			b=b->next;
		}
		curr=curr->next;
	}
	// when list runs out make sure the remaining elements are appended
	if(a!=NULL)
		curr->next=a;
	else
		curr->next=b;
	return head;
}

int main()
{
	struct node *head;
	struct node *a=NULL,*b=NULL;
	push(&a,8);
	push(&a,6);
	push(&a,4);
	push(&a,3);
	push(&a,1);
	push(&b,9);
	push(&b,5);
	push(&b,2);
	printf("the two linked list are as follows\n");
	printlist(a);
	printf("\n");
	printlist(b);
	printf("\nthe sorted list is as follows\n");
	head=sorted_merge(a,b);
	printlist(head);
	return 0;
}
