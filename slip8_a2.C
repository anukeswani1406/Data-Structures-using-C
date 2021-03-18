/*
Slip 8-2
Write a C program to create a singly linked list, reverse it and display both the list.
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
void rev();

void main()
{
	int n;
	clrscr();

	while(1)
	{
		printf("\n1. Create");
		printf("\n2. Display");
		printf("\n3. Reverse");
		printf("\n4. Exit");

		printf("\nEnter your choice : ");
		scanf("%d",&n);

		switch(n)
		{
			case 1 : create(); break;
			case 2 : display(); break;
			case 3 : rev(); break;
			case 4 : exit(0);
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

void rev()
{
	struct node *p, *q, *r;
	p=start;
	q=NULL;

	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}//while
	start=q;
}//rev