// program to swap element in linked list without swapping data
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
	int data;
	struct node* next;
};
void printlist(struct node* n)
{
	while(n!=NULL)
	{
		printf("%d",n->data);
		n=n->next;
	}
}

void swap(struct node **headref,int x,int y)
{
	//Nothing to do if x and y are same
	if(x==y)
		return; 
	// search for x (keep track of prevx and currx)
	struct node *prevx=NULL,*currx=*headref;
	while(currx&&currx->data!=x)
	{
		prevx=currx;
		currx=currx->next;
	}	
	//search for y (keep track for prevy and curry)
	struct node *prevy=NULL,*curry=*headref;
	while(curry&&curry->data!=y)
	{
		prevy=curry;
		curry=curry->next;
	}
	// if either x or y is not present nothing to do
	if(currx==NULL || curry==NULL)
		return;
	//if x is not head of linked list
	if(prevx!=NULL)
		prevx->next=curry;
	else
		*headref=curry;
	//if y is not head of linked list
	if(prevy!=NULL)
		prevy->next=currx;
	else 
		*headref=currx;
	// swap next pointers
	struct node *temp=curry->next;
	curry->next=currx->next;
	currx->next=temp;
}
/* Function to add a node at the begining of List */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling swapNodes() ");
    printlist(start);
 
    swap(&start, 4, 3);
 
    printf("\n Linked list after calling swapNodes() ");
    printlist(start);
 
    return 0;
}
