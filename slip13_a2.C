/*
Slip 13-2
Write a menu driven program using C for implementation of singly linked list.
Menu includes-
	-Create.
	-Display.
	-Insert node at specific position.
	-Search a given element in list.
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
void search();
void insert_posi();

void main()
{
	int n;
	clrscr();

	while(1)
	{
		printf("\n1. Create");
		printf("\n2. Display");
		printf("\n3. Insert Node at given Position");
		printf("\n4. Search a element");
		printf("\n5. Exit");

		printf("\nEnter your choice : ");
		scanf("%d",&n);

		switch(n)
		{
			case 1 : create(); break;
			case 2 : display(); break;
			case 3 : insert_posi(); break;
			case 4 : search(); break;
			case 5 : exit(0);
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

void insert_posi()
{
	struct node *new_node, *temp;
	int t=1, pos;

	printf("\nEnter position for new node : ");
	scanf("%d",&pos);

	temp=start;
	while(t!=(pos-1))
	{
		temp=temp->next;
		t++;
	}//while

	new_node=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data for new node : ");
	scanf("%d",&new_node->data);
	new_node->next=temp->next;
	temp->next=new_node;
}//insert

void search()
{
	int num;
	struct node *temp;

	printf("\nEnter the number to be searched : ");
	scanf("%d",&num);

	temp=start;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			printf("%d Found",num);
			return;
		}//if
		else
			temp=temp->next;
	}//while
	printf("%d not Found",num);
}//search