/*
Slip 3-2
Write a C program to create linked list with given number
in which data part of each node contains individual digit of number
(Suppose the number is 584 then the node of Linked list should contain
5, 8, 4)
*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
 int data;
 struct node *next;
}*start=NULL,*newnode,*temp;

void main()
{
 int n,rev=0,temp1;
 clrscr();

 printf("Enter the number:");
 scanf("%d",&n);

 while(n>0)
 {
  temp1=n%10;
  rev=(rev*10)+temp1;
  n=n/10;
 }

 newnode=(struct node*)malloc(sizeof(struct node));
 temp1=rev%10;
 newnode->data=temp1;
 newnode->next=NULL;

 rev=rev/10;
 start=newnode;

 while(rev>0)
 {
  newnode=(struct node*)malloc(sizeof(struct node));
  temp1=rev%10;
  newnode->data=temp1;
  newnode->next=NULL;
  rev=rev/10;
  temp=start;

  while(temp->next!=NULL)
  {
   temp=temp->next;
  }

  temp->next=newnode;
 }

 temp=start;

 while(temp!=NULL)
 {
  printf("%d %d-> ",temp->data,temp->next);
  temp=temp->next;
 }
 printf("NULL")

 getch();
}