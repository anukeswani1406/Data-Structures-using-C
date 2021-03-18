/*
Slip 1-1
Write a C program to reverse a string using
static implementation of stack.
*/

#include<stdio.h>
#include<conio.h>
#define MAX 20

int top=-1;
char stack[MAX];
char pop();
void push(char);

void main()
{
	char str[20];
	int i;
	clrscr();

	printf("\nEnter the string : ");
	gets(str);

	for(i=0;i<strlen(str);i++)
		push(str[i]);

	for(i=0;i<strlen(str);i++)
		str[i]=pop();

	printf("\nReversed string is : ");
	puts(str);

	getch();
}//main

void push(char item)
{
	if (top==(MAX-1))
	{
		printf("\nStack Overflow");
		return;
	}
	stack[++top]=item;
}

char pop()
{
	if (top==-1)
	{
		printf("\nStack Underflow");
		exit(1);
	}
	return stack[top--];
}