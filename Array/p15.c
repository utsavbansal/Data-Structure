/*Function to left Rotate arr[] of size n by 1*/
#include<stdio.h>
void leftRotatebyOne(int arr[], int n);

void rotate(int a[],int d,int n)
{
	for(int i=0;i<d;i++)
		leftRotatebyOne(a,n);
}

void leftRotatebyOne(int a[],int n)
{
	int i,temp;
	temp=a[0];
	for(i=0;i<n-1;i++)
		a[i]=a[i+1];
	a[n-1]=temp;
}

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
}

int main()
{
	int a[20],n,d;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element to rotate about\n");
	scanf("%d",&d);
	printf("after rotating \n");
	rotate(a,d,n);
	print(a,n);
	return 0;
}
