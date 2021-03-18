/*
Slip 10-2
Write a menu driven program using C for Dynamic implementation
of Queue for integers. The menu include -
	-Insert
	-Delete
	-Display
	-Exit
*/

#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *next;
}*front, *rear;

void insert(int);
void del();
void display();

void main()
{
	int n, a;
	clrscr();

	do
	{
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Display");
		printf("\n4. Exit");

		printf("\nEnter your choice");
		scanf("%d",&n);

		switch(n)
		{
			case 1 : printf("Enter the data : ");
				scanf("%d",&a);
				insert(a);
				break;

			case 2 : del(); break;

			case 3 : display(); break;

			case 4 : exit(0);
		}
	}while(1);
}//main

void insert(int a)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=a;
	new->next=NULL;

	if(front==NULL)
		front=rear=new;
	else
	{
		rear->next=new;
		rear=new;
	}
}//insert

void del()
{
	struct node *temp=front;
	if(front==NULL)
		printf("\nQueue is empty");
	else
	{
		printf("\nDeleted element is %d ",front->data);
		front=front->next;
		free(temp);
	}
}//del

void display()
{
	struct node *temp;
	if(front==NULL)
		printf("\nQueue is empty");
	else
	{
		printf("\nQueue Status\n");
		for(temp=front; temp!=NULL; temp=temp->next)
			printf("%d ",temp->data);
	}
}