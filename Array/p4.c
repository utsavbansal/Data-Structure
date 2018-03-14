//program to find element in sorted array
#include<stdio.h>
int binarysearch(int a[],int n,int key)
{
	int left=0;
	int right=n;
	int mid=(left+right)/2;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(key<a[mid])
			right=mid-1;
		else if(key>a[mid])
			left=mid+1;
		else
			return mid;
	}
	return -1;
	
}
int main()
{
	int a[20],n,key,pos;
	printf("Enter no. of many elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element you want to search\n");
	scanf("%d",&key);
	pos=binarysearch(a,n,key);
	if(pos!=-1)
		printf("the pos is %d",pos);
	else 
		printf("element does not exist");
	return 0;
}
