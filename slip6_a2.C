/*
Slip 6-2
Write a menu driven program using C for singly linked list-
	-To create linked list.
	-To display linked list.
	-To search node in linked list.
	-Insert at last position
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
void insert_end();

void main()
{
	int n;
	clrscr();

	while(1)
	{
		printf("\n1. Create");
		printf("\n2. Display");
		printf("\n3. Search a element");
		printf("\n4. Insert Node at Last Position");
		printf("\n5. Exit");

		printf("\nEnter your choice : ");
		scanf("%d",&n);

		switch(n)
		{
			case 1 : create(); break;
			case 2 : display(); break;
			case 3 : search(); break;
			case 4 : insert_end(); break;
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

void insert_end()
{
	struct node *new_node, *temp;
	temp=start;

	while(temp->next!=NULL)
		temp=temp->next;

	new_node=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data for last node : ");
	scanf("%d",&new_node->data);

	temp->next=new_node;
	new_node->next=NULL;
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