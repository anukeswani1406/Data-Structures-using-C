/*
Slip 9-1
Write a C program to sort array elements using Bubble sort method.
*/

#include<stdio.h>
#include<conio.h>
void sort(int [], int);
void main()
{
	int A[10], n, i;
	clrscr();

	printf("How many numbers : ");
	scanf("%d",&n);

	printf("\nEnter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);

	printf("\nAfter sorting : ");
	sort(A,n);
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);

	getch();
}//main

void sort(int x[], int n)
{
	int i, j, temp;
	for(j=0;j<(n-1);j++)
	{
		for(i=0;i<(n-j-1);i++)
		{
			if (x[i]>x[i+1])
			{
				temp=x[i];
				x[i]=x[i+1];
				x[i+1]=temp;
			}//if
		}//for
	}//for
}//sort