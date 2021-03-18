/*
Slip 1-2
Write a menu driven program using C for singly linked list-
	-To create linked list.
	-To display linked list.
	-To insert node at last position of linked list.
	-To delete node from specific position of linked list.
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
void insert_end();
void del_posi();

void main()
{
	int n;
	clrscr();

	while(1)
	{
		printf("\n1. Create");
		printf("\n2. Display");
		printf("\n3. Insert Node at Last Position");
		printf("\n4. Delete Node at Specific Position");
		printf("\n5. Exit");

		printf("\nEnter your choice : ");
		scanf("%d",&n);

		switch(n)
		{
			case 1 : create(); break;
			case 2 : display(); break;
			case 3 : insert_end(); break;
			case 4 : del_posi(); break;
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

void del_posi()
{
	int t, pos;
	struct node *temp, *temp1;
	t=1;
	temp=start;
	temp1=start;

	printf("\nEnter position for deleting Node : ");
	scanf("%d",&pos);

	while(t<(pos-1))
	{
		temp=temp->next;
		t++;
	}//while

	t=1;

	while(t<pos)
	{
		temp1=temp1->next;
		t++;
	}//while

	temp->next=temp1->next;
	free(temp1);
}//del