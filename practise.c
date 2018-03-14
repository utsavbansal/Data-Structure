#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void print(struct Node *n)
{
    while(n!=NULL)
    {
        printf("%d",n->data);
        n=n->next;
    }
}

void push(struct Node **headref,int data)
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=*headref;
    *headref=newnode;

}

int length(struct Node *head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;

}
int get_n_element(struct Node *n,int pos)
{
    int len=1;
    while(n!=NULL && len!=pos)
    {
        n=n->next;
        len++;
    }
    return n->data;

}

void append(struct Node *n,int d)
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    while(n!=NULL)
    {
        n=n->next;
    }
    newnode->data=d;
    newnode->next=n->next;
    n->next=newnode;
}

void main()
{
    int data;
   // struct Node **headref;
    struct Node *head=NULL,*second=NULL,*third=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    print(head);
    /*
    printf("\nEnter the data to add at first node");
    scanf("%d",&data);
    printf("the list is now\n");
    push(&head,data);
    print(head);
    */
    //printf("\nlength is :%d\n",length(head));
    /*
    int pos;
    printf("\nenter position to get element\n");
    scanf("%d",&pos);
    printf("element is :%d",get_n_element(head,pos));
    */
    printf("\n enter element to append\n");
    int d;
    scanf("%d",&d);
    append(head,d);
    print(head);
}
