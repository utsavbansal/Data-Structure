/* Program to search an element in a sorted and pivoted array*/
#include <stdio.h>
int findpivot(int [],int,int);
int bsearch(int [],int,int,int);
/* Searches an element key in a pivoted sorted array arrp[]
   of size n */

int binarysearchpivot(int a[],int n,int key)
{
	int pivot=findpivot(a,0,n-1);
	// If we didn't find a pivot, then array is not rotated at all
	if(pivot==-1)
		return bsearch(a,0,n-1,key);
	 // If we found a pivot, then first compare with pivot and then
   // search in two subarrays around pivot
	if(a[pivot]==key)
		return pivot;
	else if(a[0]<=key)
		return bsearch(a,0,pivot-1,key);
	else
		return bsearch(a,pivot+1,n-1,key);
}
/* Function to get pivot. For array 3, 4, 5, 6, 1, 2 it returns
   3 (index of 6) */

int findpivot(int a[],int low,int high)
{
	if(low>high)
		return -1;
	if(high==low)
		return low;
	int mid = (low + high)/2;   /*low + (high - low)/2;*/
   	if (mid < high && a[mid] > a[mid + 1])
       		return mid;
   	if (mid > low && a[mid] < a[mid - 1])
       		return (mid-1);
   	if (a[low] >= a[mid])
       		return findpivot(a, low, mid-1);
   	return findpivot(a, mid + 1, high);
	
}

int bsearch(int a[],int low,int high,int key)
{
	if (high < low)
       		return -1;
	int mid=(low+high)/2;
	if(a[mid]==key)
		return mid;
	else if(key>a[mid])
		return bsearch(a,mid+1,high,key);
	else
		return bsearch(a,low,mid-1,key);
}

int main()
{
	// Let us search 3 in below array
   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int n = sizeof(arr1)/sizeof(arr1[0]);
   int key = 3;
   printf("Index: %d\n", binarysearchpivot(arr1, n, key));
   return 0;
}
