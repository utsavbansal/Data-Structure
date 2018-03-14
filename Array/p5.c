//program to delete elements in sorted array
#include<stdio.h>
int insert(int arr[],int n,int key,int capacity)
{
	// Cannot insert more elements if n is already
    // more than or equal to capcity
    if (n >= capacity)
       return n;
 
    int i;
    for (i=n-1; ( i >= 0  && arr[i] > key); i--)
       arr[i+1] = arr[i];
 
    arr[i+1] = key;
 
    return (n+1);
	
		
}
int main()
{
	int a[20],n,key;
	int capacity=20;
	printf("Enter the no. of elements in array\n");
	scanf("%d",&n);
	printf("Enter the elements in ascending order \n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element to insert");
	scanf("%d",&key);
	printf("the elements after insertion are as follows\n");
	n=insert(a,n,key,capacity);
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	return 0;	
}
