/*
Slip 13-1
Write a C program to sort array elements using Insertion sort method.
*/

#include<stdio.h>
#include<conio.h>
void sort(int [], int);
void main()
{
	int A[10], n, i;
	clrscr();

	printf("Enter how many numbers to sort : ");
	scanf("%d",&n);

	printf("\nEnter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);

	printf("\nAfter Sorting : ");
	sort(A,n);
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);

	getch();
}//main

void sort(int x[10], int n)
{
	int i, j, temp;
	printf("\ntesting..\n");
	for(i=1;i<n;i++)
	{
		temp=x[i];
		j=i-1;
		while (j>=0 && x[j]>temp)
		{
			x[j+1]=x[j];
			j--;
		}//while
		x[j+1]=temp;
	}//for
}//sort