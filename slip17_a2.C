/*
Slip 17-2
Write a C program to create a random array of n integers.
Sort the array using Bubble sort.
Accept a value x from user and use linear search algorithm to check 
whether the number is present in array or not.
*/

#include<stdio.h>
#include<conio.h>
void sort(int [], int);
int search(int[], int, int);
void main()
{
	int A[10], n, i, num, pos;
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

	printf("\nEnter the number to be searched : ");
	scanf("%d",&num);

	pos=search(A,num,n);
	if(pos==-1)
		printf("\nNumber not found");
	else
		printf("\nNumber found at %d position",pos+1);
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

int search(int A[], int num, int  n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(A[i]==num)
			return i;
	}//for
	return -1;
}//search