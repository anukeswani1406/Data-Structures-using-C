/*
Slip 18-1
Write a C program to sort the elements using Quick sort method.
*/

#include<stdio.h>
#include<conio.h>
void sort(int [], int, int);
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
	sort(A,0,n-1);
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);

	return 0;
}//main

void sort(int x[], int low, int high)
{
	int pivot, i, j, temp;

	if (low<high)
	{
		pivot=x[low];
		i=low+1;
		j=high;
		while (i<=j)
		{
			while (x[i]<=pivot && i<=high)
				i++;
			
			while (x[j]>pivot && j>=low)
				j--;
	
			if (i<j)
			{
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}//if
		}//while

//here i and j will cross each other
		temp=x[j];
		x[j]=pivot;
		x[low]=temp;
	
		sort(x,low,j-1);
		sort(x,j+1,high);
	}//if
}//sort