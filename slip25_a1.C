/*
Slip 25-1
Write a C program to create doubly linked list
and display nodes having even values.
*/


#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *start=NULL, *end=NULL;

void insert();
void show();
void even();

void main()
{
	int ch;
	clrscr();

	do
	{
		printf("\nMAIN MENU");
		printf("\n1. Insert");
		printf("\n2. Show");
		printf("\n3. Display nodes having even values");
		printf("\n4. Exit");

		printf("\nENTER YOUR CHOICE\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: insert(); break;
			case 2: show(); break;
			case 3: even(); break;
			case 4: exit(0);
		}
	}while(1);
}//main

void insert()
{
	struct node *temp, *move;
	int num;
	temp=(struct node*)malloc(sizeof(struct node));

	printf("\nEnter the number : ");
	scanf("%d",&num);
	temp->left=NULL;
	temp->right=NULL;
	temp->data=num;

	if(start==NULL)
	{
		start=temp;
		end=temp;
	}
	else
	{
		move=start;
		while(move->right!=NULL)
		{
			move=move->right;
		}
		move->right=temp;
		temp->left=move;
		end=temp;
	}//else
}//insert()

void show()
{
	struct node *move;

	if(start==NULL)
		printf("\nlist is empty\n");
	else
	{
		move=start;
		while(move->right!=NULL)
		{
			printf("%d ",move->data);
			move=move->right;
		}
		printf("%d",move->data);
	}
}//show()

void even()
{
	struct node *temp;
	temp=start;

	while(temp!=NULL)
	{
		if(temp->data%2==0)
			printf("%d ",temp->data);
		temp=temp->right;
	}
}//even