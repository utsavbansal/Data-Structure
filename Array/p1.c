// program to find element in unsorted array
#include<stdio.h>
int find(int arr[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
			return i;
	}
	return -1;
	
}
int main()
{
	int arr[]={12,3,4,6,30};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key,pos;
	printf("the array is {12,3,4,5,30}\n ");
	printf("Enter the element you want to search\n");
	scanf("%d",&key);
	pos=find(arr,n,key);
	if(pos==-1)
		printf("element does not exist");
	else
		printf("element present at %d",pos);
	return 0;
}
