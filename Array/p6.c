// program to delete element in sorted array
#include<stdio.h>
int delete(int a[],int n,int key)
{
	int i,pos;
	for(i=0;i<n ;i++)
		if(a[i]==key)
		{	pos=i;
			break;
		}
	for (i=pos; i<n; i++)
        a[i] = a[i+1];
	return n-1; 
}

int main()
{
	int a[20],n,key;
	printf("Enter the no. of elements in array");
	scanf("%d",&n);
	printf("Enter the elements");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element to delete\n");
	scanf("%d",&key);
	n=delete(a,n,key);
	printf("the new elements are\n");
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	return 0;
}
