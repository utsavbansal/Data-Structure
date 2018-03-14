// Recursive C program for level order traversal of Binary Tree
#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data)
{
	struct node *node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int height(struct node *node);
void printgivenorder(struct node *node,int level);


void printlevel(struct node* node)
{
	
	int h=height(node);
	int i;
	for(i=1;i<=h;i++)
		printgivenorder(node,i);
}

int height(struct node *node)
{
	if(node==NULL)
		return 0;
	/* compute the height of each subtree */
	int lheight=height(node->left);
	int rheight=height(node->right);
	/* use the larger one */
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
}

void printgivenorder(struct node *node,int level)
{
	if(node==NULL)
		return;
	if(level==1)
		printf("%d",node->data);
	else if(level>1)
		{
			printgivenorder(node->left,level-1);
			printgivenorder(node->right,level-1);
		}
}

int main()
{
	struct node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);

	 printf("Level Order traversal of binary tree is \n");
	printlevel(root);
	return 0;
}
