// program to find missing number in array
#include<stdio.h>

int findnumber(int a[],int n)
{
	int total=(n+1)*(n+2)/2;
	int i;
	for(i=0;i<n;i++)
		total-=a[i];
	return total;
}
	
int main()
{
	int a[20],n,misno;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	misno=findnumber(a,n);
	printf("the missing no is %d",misno);
	return 0;
}
