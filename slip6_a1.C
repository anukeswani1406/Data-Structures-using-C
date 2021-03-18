/*
Slip 6-1
Write a C program to search given elements into the list using
Non-Recursive Binary search method.
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
	int i=0, j=n-1, mid;
	while (i<j)
	{
		mid=(i+j)/2;
		if (num==x[mid])
			return mid;
		else if (num>x[mid])
			i=mid+1;
		else
			j=mid-1;
	}//while
	return -1;
}//search