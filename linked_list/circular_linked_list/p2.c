//program to split circular list into two halve
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int data)
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->next=*head;
	struct node *temp=*head;
	if(*head!=NULL)
	{	
		while(temp->next!=*head)
			temp=temp->next;
		temp->next=new;
	}
	else
		new->next=new;
	*head=new;
}
void printlist(struct node *head)
{
	struct node *temp=head;
	if(head!=NULL)
	{
		do
		{
			printf("%d",temp->data);
			temp=temp->next;
		}while(temp!=head);
	}
}

void split(struct node *head,struct node **head1,struct node **head2)
{
	struct node *fast_ptr=head;
	struct node *slow_ptr=head;
	if(head==NULL)
		return;
	while(fast_ptr->next!=head && fast_ptr->next->next!=head)
	{
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
	}
	
}

/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head nodes of 
    the two resultant linked lists */
void splitList(struct node *head, struct node **head1_ref, 
                                            struct node **head2_ref)
{
  struct node *slow_ptr = head;
  struct node *fast_ptr = head; 
 
  if(head == NULL)
    return;
  
  /* If there are odd nodes in the circular list then
     fast_ptr->next becomes head and for even nodes 
     fast_ptr->next->next becomes head */
  while(fast_ptr->next != head &&
         fast_ptr->next->next != head) 
  {
     fast_ptr = fast_ptr->next->next;
     slow_ptr = slow_ptr->next;
  }  
 
 /* If there are even elements in list then move fast_ptr */
  if(fast_ptr->next->next == head)
    fast_ptr = fast_ptr->next;      
   
  /* Set the head pointer of first half */
  *head1_ref = head;    
      
  /* Set the head pointer of second half */
  if(head->next != head)
    *head2_ref = slow_ptr->next;
   
  /* Make second half circular */  
  fast_ptr->next = slow_ptr->next;
   
  /* Make first half circular */  
  slow_ptr->next = head;       
}


/* Driver program to test above functions */
int main()
{
  int list_size, i; 
   
  /* Initialize lists as empty */
  struct node *head = NULL;
  struct node *head1 = NULL;
  struct node *head2 = NULL;  
 
  /* Created linked list will be 12->56->2->11 */
  push(&head, 12); 
  push(&head, 56);   
  push(&head, 2);   
  push(&head, 11);   
 
  printf("Original Circular Linked List");
  printlist(head);      
  
  /* Split the list */
  splitList(head, &head1, &head2);
  
  printf("\nFirst Circular Linked List");
  printlist(head1);  
 
  printf("\nSecond Circular Linked List");
  printlist(head2);  
   
  getchar();
  return 0;
} 
