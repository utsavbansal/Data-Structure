// program to reverse an array
#include<stdio.h>

void reverse(int a[],int start,int end)
{
	int temp;
	while(start<end)
	{
		temp=a[start];
		a[start]=a[end];
		a[end]=temp;
		start++;
		end--;
	}
}

void print(int a[],int size)
{
	for(int i=0;i<size;i++)
		printf("%d",a[i]);
}

int main()
{
	int a[20],n;
	printf("Enter elements in array\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	reverse(a,0,n-1);
	printf("after reverse\n");
	print(a,n);
	return 0;
}
