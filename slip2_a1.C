/*
Slip 2-1
Write a C program to evaluate a given polynomial using function.
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
void create(int [], int);
void display(int [], int);
int eval(int [], int, float);
void main()
{
	int x[10], m, n;
	int val;
	clrscr();

	printf("Enter highest degree of poly : ");
	scanf("%d",&n);
	create(x,n);

	printf("\nEnter the value : ");
	scanf("%d",&val);

	printf("\nPoly is : ");
	display(x,n);

	printf("\nAnswer = %d",eval(x,n,val));

	getch();
}//main

void create(int x[], int n)
{
	int i;
	for (i=n;i>=0;i--)
	{
		printf("Enter the %d coeff : ",i);
		scanf("%d",&x[i]);
	}//for
}//create

void display(int x[], int n)
{
	int i;
	for(i=n;i>0;i--)
		printf("%dx^%d + ",x[i],i);
	printf("%dx^%d",x[i],i);
}//display

int eval(int x[], int n, float val)
{
	int ans=0;
	int i;
	for(i=n;i>=0;i--)
		ans=ans+x[i]*pow(val,i);
	return ans;
}//eval