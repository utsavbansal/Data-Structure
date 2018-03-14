/*

A Product Array Puzzle

Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. Solve it without division operator and in O(n).

Example:
arr[] = {10, 3, 5, 6, 2}
prod[] = {180, 600, 360, 300, 900}
*/

#include<stdio.h>
#include<stdlib.h>

/* Function to print product array for a given array
 arr[] of size n */
void productArray(int a[],int n)
{
	/* Allocate memory for temporary arrays left[] and right[] */
	int *left=(int *)malloc(sizeof(int));
	int *right=(int *)malloc(sizeof(int));
	
	int i,j;
	/* Rightmost most element of right array is always 1 */
	right[n-1]=1;
	
	/* Left most element of left array is always 1 */
	left[0]=1;
	
	/* Construct the left array */
	for(i=1;i<n;i++)
		left[i]=a[i-1]*left[i-1];
	
	/* Construct the right array */
	for(j=n-2;j>=0;j--)
		right[j]=a[j+1]*right[j+1];
	
	/* Allocate memory for the product array */
	int *product=(int *)malloc(sizeof(int));
	
	/* Construct the product array using
    		left[] and right[] */
	for(i=0;i<n;i++)
		product[i]=left[i]*right[i];
	
	//print the product array
	for(i=0;i<n;i++)
		printf("%d",product[i]);
	
	return ;	
}

/* Driver program to test above functions */
int main()
{
  int arr[] = {10, 3, 5, 6, 2};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("The product array is: \n");
  productArray(arr, n);
  getchar();
}
