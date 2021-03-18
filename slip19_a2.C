/*
Slip 19-2
Write a C program to read n integers and create two lists such
that all positive numbers are in one list and negative numbers
are in another list. Display both the list.
*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>

void create1(int);
void create2(int);
void display1();
void display2();

struct node
{
 int data;
 struct node *next;
}*start1=NULL,*start2=NULL,*temp,*newnode;

void main()
{
 int n,num;
 clrscr();

 printf("\nEnter no of elements: ");
 scanf("%d",&n);

 while(n>0)
 {
  printf("\nEnter element: ");
  scanf("%d",&num);

  if(num>=0)
    create1(num);
  else
    create2(num);
  n--;
 }

 display1();
 printf("\n");

 display2();

 getch();
}

void create1(int num)
{
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=num;
 newnode->next=NULL;
 if(start1==NULL)
 {
  start1=newnode;
 }
 else
 {
  temp=start1;
  while(temp->next!=NULL)
  {
   temp=temp->next;
  }
  temp->next=newnode;
 }
}

void create2(int num)
{
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=num;
 newnode->next=NULL;
 if(start2==NULL)
 {
  start2=newnode;
 }
 else
 {
  temp=start2;
  while(temp->next!=NULL)
  {
   temp=temp->next;
  }
  temp->next=newnode;
 }
}

void display1()
{
 temp=start1;
 while(temp!=NULL)
 {
  printf(" %d-> ",temp->data);
  temp=temp->next;
 }
 printf("NULL");
}

void display2()
{
 temp=start2;
 while(temp!=NULL)
 {
  printf(" %d-> ",temp->data);
  temp=temp->next;
 }
 printf("NULL");
}