//program to Given an array A[] and a number x, check for pair in A[] with sum as x
#include<stdio.h>
#define bool int


void exchange(int *a,int *b)
{	
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


int partition(int a[],int si,int ei)
{
	int x=a[ei];
	int i=si-1;
	int j;
	for(j=si;j<=ei-1;j++)
	{
		if(a[j]<=x)
		{
			i++;
			exchange(&a[i],&a[j]);
		}
	}
	exchange(&a[i+1],&a[ei]);
	return(i+1);
}

void quicksort(int a[],int si,int ei)
{
	int pi;		/* Partitioning index */
	if(si<ei)
	{
		pi=partition(a,si,ei);
		quicksort(a,si,pi-1);
		quicksort(a,pi+1,ei);
	}
}


int check(int a[],int n,int x)
{
	int l,r;
	quicksort(a,0,n-1);
	l=0;
	r=n-1;
	while(l<r)
	{
		if(a[l]+a[r]==x)
			return 1;
		else if(a[l]+a[r]<x)
			l++;
		else
			r--;
	}
	return 0;
	
}

int main()
{
	int a[20],n,sum;
	printf("Enter the no. of elements in array\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the sum to check\n");
	scanf("%d",&sum);
	if(check(a,n,sum))
		printf("\npresent");
	else
		printf("\nnot present");
	return 0;
}
