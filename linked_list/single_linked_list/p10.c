// program to search element in linked list iteratively
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
	int data;
	struct node* next;
};
bool search(struct node *n,int key)
{
	struct node *tmp=n;
	while(tmp!=NULL)
	{
		if(tmp->data==key)
			return true;
		tmp=tmp->next;
	}
	return false;
}

int main()
{
	int key;
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
	printf("Enter the element of linklist to be searched");
	scanf("\n%d",&key);
	search(head,key)? printf("yes"):printf("no");
	return 0;
}





