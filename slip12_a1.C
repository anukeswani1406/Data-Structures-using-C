/*
Slip 12-1
Write a C program to create a Circular singly linked list and display it.
*/

#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *next;
}*start=NULL;

void create();
void display();

void main()
{
	int n;
	clrscr();

	while(1)
	{
		printf("\n1. Create");
		printf("\n2. Display");
		printf("\n3. Exit");

		printf("\nEnter your Choice : ");
		scanf("%d",&n);

		switch(n)
		{
			case 1 : create(); break;
			case 2 : display(); break;
			case 3 : exit(0);
		}//switch
	}//while
	getch();
}//main

void create()
{
	int i, n, num;
	struct node *new_node, *temp;

	printf("\nHow many nodes you want to create : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter data for node %d : ",i+1);
		scanf("%d",&num);
		new_node->data=num;
		new_node->next=NULL;

		if(start==NULL)
		{
			start=new_node;
			start->next=start;
		}
		else
		{
			temp=start;
			while(temp->next!=start)
				temp=temp->next;
			temp->next=new_node;
			new_node->next=start;
		}
	}//for
}//create

void display()
{
	struct node *temp;
	printf("\nThe Linked List is : \n");
	temp=start;
	while(temp->next!=start)
	{
		printf("%d %d %d ->",&temp->data, temp->data, temp->next);
		temp=temp->next;
	}//while
	printf("%d %d %d",&temp->data, temp->data, temp->next);
}//display