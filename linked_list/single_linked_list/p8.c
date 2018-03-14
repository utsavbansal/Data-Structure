// program to count length of linked list iteratively
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
int count(struct node *n)
{
	int length=0;
	while(n!=NULL)
	{
		n=n->next;
		length++;	
	}
	return length;	
}

int main()
{
	int len;
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
	len=count(head);
	printf("length of linklist is as follows\n %d",len);
	return 0;
}
