/*
Slip 25-2
Write menu driven using C for Dynamic implemenetation of stack.
the menu includes following opertions :
	-push
	-pop
	-display
	-exit
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
}*top;

void init();
void push();
void pop();
void peek();
void isEmpty();

int main()
{
	int ch;
	while(1)
	{
		printf("\n---------Dynamic Stack-------\n");
		printf("\n1.Init\n");
		printf("2.Push\n");
		printf("3.Pop\n");
		printf("4.Peek\n");
		printf("5.IsEmpty\n");
		printf("6.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:init();  break;
			case 2:push(); break;
			case 3:pop(); break;
			case 4:peek(); break;
			case 5:isEmpty(); break;
			case 6:exit(0);
		}//switch
	}//while
}//main()

void init()
{
top=NULL;
printf("\nDynamic Stack is initialized\n");
}

void push()
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("\nEnter the value:");
scanf("%d",&temp->data);
temp->next=top;
top=temp;
}

void pop()
{
struct node *temp;
if(top==NULL)
printf("\nDynamic Stack is empty\n");
else
{
temp=top;
printf("\nDeleted value from Dynamic stack is %d",temp->data);
top=top->next;
free(temp);
}
}

void peek()
{
if(top==NULL)
printf("\nDynamic Stack is empty\n");
else
printf("Value at top of Dynamic stack is:%d",top->data);
}

void isEmpty()
{
if(top==NULL)
printf("\nDynamic Stack is empty\n");
else
printf("\nDynamic Stack is not empty\n");
}
