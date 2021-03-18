/*
Slip 19-1
Write a C program to sort the array elements in ascending order using Merge sort method.
*/

#include<stdio.h>
#include<conio.h>
void mergesort(int [], int, int);
void merge(int [], int, int, int);
int main()
{
	int A[10], n, i;
	clrscr();

	printf("Enter how many numbers to sort : ");
	scanf("%d",&n);

	printf("\nEnter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);

	printf("\nAfter Sorting : ");
	mergesort(A,0,n-1);
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);

	return 0;
}//main

void mergesort(int x[10], int low, int high)
{
	int mid;
	if (low<high)
	{
		mid=(low+high)/2;
		mergesort(x,low,mid);
		mergesort(x,mid+1,high);
		merge(x,low,mid,high);
	}//if
}//mergesort

void merge(int x[10], int low, int mid, int high)
{
	int i,j,k,y[20];
	i=low;
	j=mid+1;
	k=0;
	while((i<=mid)&&(j<=high))
	{
		if(x[i]<=x[j])
			y[k++]=x[i++];
		else
			y[k++]=x[j++];
	}//while

	while(i<=mid)
		y[k++]=x[i++];

	while(j<=high)
		y[k++]=x[j++];
	
	for(j=low,k=0;j<=high;j++,k++)
		x[j]=y[k];
}//merge