// C program to implement insert operation in
// an unsorted array.
#include<stdio.h>
int insert(int arr[],int n,int key,int capacity)
{
	if(n>=capacity)
		return n;
	arr[n]=key;
		
		
		return n+1;
	
}

int main()
{
	int arr[20]={12,3,4,5,6,7};
	int capacity=sizeof(arr)/sizeof(arr[0]);
	int n=6;
	int key;
	printf("the array is {12,3,4,5,6,7}\nEnter the element you want to insert");
	scanf("%d",&key);
	n=insert(arr,n,key,capacity);
	printf("the after insertion is as follows\n");
	for(int i=0;i<n;i++)
		printf("%d",arr[i]);
	return 0;
	 
}
