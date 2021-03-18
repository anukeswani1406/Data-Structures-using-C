/*
Slip 21-1
Write a C program to create two singly linked lists and concatenate one list at the end of another list.
*/

#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *next;
}*start=NULL, *start1=NULL;

void create();
void display();
void create1();
void display1();
void concat();

void main()
{
	int n;
	clrscr();

	while(1)
	{
		printf("\n1. Create 1st List");
		printf("\n2. Display 1st List");
		printf("\n3. Create 2nd List");
		printf("\n4. Display 2nd List");
		printf("\n5. Concatenate");
		printf("\n6. Exit");

		printf("\nEnter your choice : ");
		scanf("%d",&n);

		switch(n)
		{
			case 1 : create(); break;
			case 2 : display(); break;
			case 3 : create1(); break;
			case 4 : display1(); break;
			case 5 : concat(); break;
			case 6 : exit(0);
		}//switch
	}//while
}//main

void create()
{
	int i, n, num;
	struct node *new_node, *temp;

	printf("\nHow many nodes to create : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		printf("Enter data for node %d : ",i+1);
		scanf("%d",&num);
		new_node->data=num;
		new_node->next=NULL;

		if(start==NULL)
			start=new_node;
		else
		{
			temp=start;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=new_node;
		}
	}//for
}//create

void display()
{
	struct node *temp;
	printf("\nThe Linked List : \n");
	temp=start;
	while(temp!=NULL)
	{
		printf("%d %d -> ",temp->data,temp->next);
		temp=temp->next;
	}//while
	printf("NULL");
}//display

void create1()
{
	int i, n, num;
	struct node *new_node, *temp;

	printf("\nHow many nodes to create : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		printf("Enter data for node %d : ",i+1);
		scanf("%d",&num);
		new_node->data=num;
		new_node->next=NULL;

		if(start1==NULL)
			start1=new_node;
		else
		{
			temp=start1;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=new_node;
		}
	}//for
}//create

void display1()
{
	struct node *temp;
	printf("\nThe Linked List : \n");
	temp=start1;
	while(temp!=NULL)
	{
		printf("%d %d -> ",temp->data,temp->next);
		temp=temp->next;
	}//while
	printf("NULL");
}//display

void concat()
{
	struct node *temp;
	temp=start;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=start1;
}	