/*
Slip 2-2
Write a C program to accept an infix expression
convert it into its postfix expresion and
display the result
*/

#include<stdio.h>

#define MAX 10
#define FULL MAX-1
#define EMPTY -1

//Self Referencial Structure
typedef struct
{
	int top;
	char data[MAX];
}stack;

//Initialize top of the stack
initstack(stack *sp)
{
	sp->top=EMPTY;
	return 0;
}
//inserts element at top of stack
void push(stack *sp,char c)
{
	if(isfull(sp))
		printf("\n The stack is full");
	else
	{
		sp->top++;
		sp->data[sp->top]=c;
	}
}
//removes element at top of stack
pop(stack *sp)
{
	char c;
	c=sp->data[sp->top];
	sp->top--;
	return(c);
}
//checks stack is full or not
isfull(stack *sp)
{
	if(sp->top==FULL)
		return(1);
	else
		return 0;
}
//checks stack is empty or not
isempty(stack *sp)
{
	if(sp->top==EMPTY)
		return(1);
	else
		return 0;
}
//gives element at top position
stacktop(stack *sp)
{
	return(sp->data[sp->top]);
}
//gives priority of supplied operator
priority(char c)
{
	if(c=='(')
		return(0);
	if(c=='+' || c=='-')
		return(1);
	if(c=='*' || c=='/' || c=='%')
		return(2);
	if(c=='^')
		return(3);
}

main()
{
	stack stack1;
	char infix[20],postfix[20],ch;
	int i,j;
	printf("Enter the infix string: ");
	scanf("%s",infix);
	initstack(&stack1);
	i=j=0;
	while(infix[i]!='\0')
	{
		if((infix[i]>='A' && infix[i]<='Z') || (infix[i]>='a' && infix[i]<='z'))
		{
			postfix[j]=infix[i];
			j++;
		}
		else if(infix[i]=='(')
			push(&stack1,infix[i]);
		else if(infix[i]=='^' || infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix
			[i]=='/' || infix[i]=='%')
		{
			while(priority(infix[i])<=priority(stacktop(&stack1)) && !isempty(&stack1))
			{
				ch=pop(&stack1);
				postfix[j]=ch;
				j++;
			}
			push(&stack1,infix[i]);
		}
		else if(infix[i]==')')
		{
			ch=pop(&stack1);
			while(!isempty(&stack1) && ch!='(')
			{
				postfix[j]=ch;
				j++;
				ch=pop(&stack1);
			}
		}
		i++;
	}//while
	while(!isempty(&stack1))
	{
		ch=pop(&stack1);
		postfix[j]=ch;
		j++;
	}
	postfix[j]='\0';
	printf("\nThe postfix expression is:  %s\n\n",postfix);
	return 0;
}


//(A*B+C) => AB*C+
//A+B/C-D => ABC/+D-
//(A+B)*C/D  => AB+C*D/
//A-B/(C*D^E)  =>  ABCDE^*/-
//A+(B-C*D)^E) =>  ABCD*-E^+
//A*(B+^D)-E/F*(G+D)  => ABD^+*EF/GD+*-
//(A+B)*C/D+E^F/G  => AB+C*D/EF^G/+
//A+B*C/D=>ABC*D/+
