/*
Slip 24-2
Write menu driven program using C for circular doubly linked list.
the menu includes
	-Create
	-Display
	-Exit
*/


#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *start=NULL, *end=NULL;

void create();
void display();

void main()
{
	int ch;
	clrscr();

	do
	{
		printf("\nMAIN MENU");
		printf("\n1. Create");
		printf("\n2. Display");
		printf("\n3. Exit");

		printf("\nENTER YOUR CHOICE\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: create(); break;
			case 2: display(); break;
			case 3: exit(0);
		}
	}while(1);
}//main

void create()
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
		temp->right=start;
	}
	else
	{
		move=start;
		while(move->right!=start)
		{
			move=move->right;
		}
		move->right=temp;
		temp->left=move;
		end=temp;
		temp->right=start;
		start->left=temp;
	}//else
}//create()

void display()
{
	struct node *move;

	if(start==NULL)
		printf("\nlist is empty\n");
	else
	{
		move=start;
		while(move->right!=start)
		{
			printf(" %d %d %d ->",move->left, move->data, move->right);
			move=move->right;
		}
		printf(" %d %d %d",move->left, move->data, move->right);
	}
}//display()