/*
Slip 14-1
Write a C program to sort array elements in ascending order using Selection sort method.
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

void sort(int x[], int n)
{
	int i, j, temp;
	for(i=0;i<(n-1);i++)
	{
		for(j=i+1;j<n;j++)
		{
			if (x[i]>x[j])
			{
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}//if
		}//for
	}//for
}//sort