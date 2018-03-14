/*

k largest(or smallest) elements in an array | added Min Heap method

Question: Write an efficient program for printing k largest elements in an array. Elements in array can be in any order.

For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements i.e., k = 3 then your program should print 50, 30 and 23.


Method 2 (Use temporary array)
K largest elements from arr[0..n-1]

1) Store the first k elements in a temporary array temp[0..k-1].
2) Find the smallest element in temp[], let the smallest element be min.
3) For each element x in arr[k] to arr[n-1]
If x is greater than the min then remove min from temp[] and insert x.
4) Print final k elements of temp[]

Time Complexity: O((n-k)*k). If we want the output sorted then O((n-k)*k + klogk)

Thanks to nesamani1822 for suggesting this method. 
*/


#include<stdio.h>
void printarray(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
void findmin(int temp[],int k)
{
	int i,min,index,flag=0,t;
	min=temp[0];
	for(i=0;i<k;i++)
		if(min>temp[i])
			{min=temp[i];
			index=i;
			 flag=1;	// for indicating that index is initialised
			}
	if(flag==1)
	{
	t=temp[0];	// store min value at index zero
	temp[0]=min;
	
	temp[index]=t;
	}
	
}
void exchange(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void findlargest(int a[],int n,int temp[],int k)
{
	int i,j;
	for(i=0;i<k;i++)
		temp[i]=a[i];
	findmin(temp,k);
	while(i<n)
	{
		if(temp[0]<a[i])
			{
				exchange(&temp[0],&a[i]);
				
			}
		findmin(temp,k);
		i+=1;	
	}
}

int main()
{
	int i,a[20],tmp[10],k,n;
	printf("Enter no. of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the no of largest elements\n");
	scanf("%d",&k);
	findlargest(a,n,tmp,k);
	printarray(tmp,k);
	return 0;
}
