// insert the node  At the front of the linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void printlist(struct node* n)
{
	while(n!=NULL)
	{
		printf("%d ",n->data);
		n=n->next;
	}
}
// funtion to insert the node at given prev node
void insert(struct node* prev_node,int new_data)
{
	if(prev_node->next==NULL)
	{
		printf("node cannot be null enter again");
		return ;
	}
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	// assign the next of new node to prev next
	new_node->next=prev_node->next;
	// assign prev next to new node
	prev_node->next=new_node;
}
int main()
{
	int new_data;
	struct node *head=NULL,*second=NULL,*third=NULL;
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;
	printf("Before insertion linked list is as follows\n");
	printlist(head);
	printf("\nEnter the data to be inserted after second node\n");
	scanf("%d",&new_data);
	// call the push function
	insert(second,new_data);
	printlist(head);
	return 0;
}
