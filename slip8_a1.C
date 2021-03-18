/*
Slip 8-1
Write a C program to create a 1D table of integers whose size
will be specified at run time
(array using dynamic memory allocation)
*/

#include<stdio.h>
#include<alloc.h>
#include<conio.h>
void main()
{
	int *a,i,n;
	clrscr();

	printf("Enter how many numbers:");
	scanf("%d",&n);

	a=(int *)calloc(n,sizeof(int));
	printf("Enter array elements:\n");

	//When the pointer is incremented its value is incremented
	//by the length of datatype that it points to.

	for(i=0;i<n;i++)
		scanf("%d",(a+i));

	printf("\n\nArray is:\n\n");
	for(i=0;i<n;i++)
		printf("%d\t",*(a+i));

	getch();
}
