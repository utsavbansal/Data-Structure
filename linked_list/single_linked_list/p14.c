//program to get middle node from linked list
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


/* Function to get the middle of the linked list
void printMiddle(struct node *head)
{
    int count = 0;
    struct node *mid = head;
 
    while (head != NULL)
    {
        // update mid, when 'count' is odd number 
        if (count & 1)
            mid = mid->next;
 
        ++count;
        head = head->next;
    }
 
    // if empty list is provided 
    if (mid != NULL)
        printf("The middle element is [%d]\n\n", mid->data);
}


*/

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
// function to get mid element of linked list
int getelement(struct node *head)
{	
	struct node *tmp=head;							
	int count=0,mid;
	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	mid=count/2;
	count=0;
	printf("%d",mid);
	while(tmp!=NULL)
	{
		if(mid==count)
			return(tmp->data);
		count++;
		tmp=tmp->next;
	}
	assert(0);
	 
}
// Driver function
int main()
{
	int element;
	struct node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	printf("the linked list is as follows\n");
	printlist(head);
	element=getelement(head);
	printf("\nthe element is %d ",element);
	return 0;	
}



