/*
Slip 20-1
Write a C Program to read postfix expression,
evaluate it and display the result.
*/

#include<stdio.h>
#define MAX 20
#define EMPTY -1

typedef struct node
{
	int top;
	char items[MAX];
}stack;

main()
{
	int r;
	char line[20];
	printf("\n Enter the postfix expression: ");
	scanf("%s",line);
	r=evaluatepostfix(line);
	printf("\nThe value of postfix string is:%d\n\n",r);
	return 0;
}

evaluatepostfix(char postfix[MAX])
{
	stack s1;
	int i,a,b,c,d,e,res,opnd1,opnd2;
	initstack(&s1);
	printf("\n Enter the value of A,B,C,D,E: ");
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(i=0;postfix[i]!='\0';i++)
	{
		switch(postfix[i])
		{
			case 'a':
			case 'A':push(&s1,a);
					 break;
			case 'b':
			case 'B':push(&s1,b);
					 break;
			case 'c':
			case 'C':push(&s1,c);
					 break;
			case 'd':
			case 'D':push(&s1,d);
					 break;
			case 'e':
			case 'E':push(&s1,e);
					 break;
			default:opnd2=pop(&s1);
				opnd1=pop(&s1);
		}
		switch(postfix[i])
		{
			case '+':res=opnd1+opnd2;
					 push(&s1,res);
					 break;
			case '-':res=opnd1-opnd2;
					 push(&s1,res);
					 break;
			case '*':res=opnd1*opnd2;
					 push(&s1,res);
					 break;
			case '/':res=opnd1/opnd2;
					 push(&s1,res);
					 break;
			case '%':res=opnd1%opnd2;
					 push(&s1,res);
					 break;
		}
	}
	res=pop(&s1);
	return(res);
}

initstack(stack *sp)
{
	sp->top=EMPTY;
	return 0;
}

push(stack *sp,int num)
{
	if(isfull(sp))
		printf("\n the stck is full: ");
	else
	{
		sp->top++;
		sp->items[sp->top]=num;
	}
	return 0;
}

pop(stack *sp)
{
	int num;
	if(isempty(sp))
		printf("\n The stack is empty");
	else
	{
		num=sp->items[sp->top];
		sp->top--;
	}
	return(num);
}

isfull(stack *sp)
{
	if(sp->top==MAX-1)
		return(1);
	else
		return(0);
}

isempty(stack *sp)
{
	if(sp->top==EMPTY)
		return(1);
	else
		return(0);
}

/***********Output********


Enter the postfix expression: AB+C-

Enter the value of A,B,C,D,E: 5
3
2
0
0
The value of postfix string is:6 */




