/*
Slip 5-1
Write a C program for addition of two polynomials using array.
*/

#include<stdio.h>
#include<conio.h>
void create(int [], int);
void display(int [], int);
void add(int [], int [], int, int, int []);
void main()
{
	int A[10], B[10], m, n, C[10];
	clrscr();

	printf("Enter highest degree of first polynomial :");
	scanf("%d",&m);
	create(A,m);

	printf("\nEnter highest degree of second polynomial :");
	scanf("%d",&n);
	create(B,n);

	add(A,B,m,n,C);

	printf("\nFirst polynomial is : ");
	display(A,m);

	printf("\nSecond polynomial is : ");
	display(B,n);

	printf("\nResultant is : ");
	if (m>n)
		display(C,m);
	else
		display(C,n);
	getch();
}//main

void create (int x[], int n)
{
	int i;
	for (i=n;i>=0;i--)
	{
		printf("Enter the %d Coeff : ",i);
		scanf("%d",&x[i]);
	}//for
}//create

void display (int x[], int n)
{
	int i;
	for (i=n;i>0;i--)
		printf("%dx^%d + ",x[i],i);
	printf("%dx^%d",x[i],i);
}//display

void add(int x[], int y[], int a, int b, int z[])
{
	int i,j;
	if (a>b)
		for(i=a;i>b;i--)
			z[i]=x[i];
	else
		for(i=b;i>a;i--)
			z[i]=y[i];
	for(j=i;j>=0;j--)
		z[j]=x[j]+y[j];
}//add