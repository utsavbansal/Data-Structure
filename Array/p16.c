/*
Let AB are the two parts of the input array where A = arr[0..d-1] and B = arr[d..n-1]. The idea of the algorithm is:
Reverse A to get ArB.  Ar is reverse of A 
Reverse B to get ArBr.  Br is reverse of B 
Reverse all to get (ArBr) r = BA.
For arr[] = [1, 2, 3, 4, 5, 6, 7], d =2 and n = 7
A = [1, 2] and B = [3, 4, 5, 6, 7]
Reverse A, we get ArB = [2, 1, 3, 4, 5, 6, 7]
Reverse B, we get ArBr = [2, 1, 7, 6, 5, 4, 3]
Reverse all, we get (ArBr)r = [3, 4, 5, 6, 7, 1, 2]
*/

// C/C++ program for reversal algorithm of array rotation
#include<stdio.h>
void reverse(int a[],int start,int end)
{
	int tmp;
	while(start<end)
	{
		tmp=a[start];
		a[start]=a[end];
		a[end]=tmp;
		start++;
		end--;
	}
}

void rotate(int a[],int d,int n)
{
	reverse(a,0,d-1);
	reverse(a,d,n-1);
	reverse(a,0,n-1);
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
