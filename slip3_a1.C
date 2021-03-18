/*
Slip 3-1
Write a C program for implementing Linear search using function.
*/

#include<stdio.h>
#include<conio.h>
int search(int [], int, int);
void main()
{
	int i, A[10], n, ans, num;
	clrscr();

	printf("How many elements : ");
	scanf("%d",&n);

	printf("\nEnter the elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);

	printf("\nEnter number to find : ");
	scanf("%d",&num);

	ans=search(A,n,num);

	if (ans==-1)
		printf("\nNumber not found");
	else
		printf("\nNumber is at %d location",ans+1);

	getch();
}//main

int search(int x[], int n, int num)
{
	int i;
	for(i=0;i<n;i++)
	{
		if (x[i]==num)
			return i;
	}//for
	return -1;
}//search