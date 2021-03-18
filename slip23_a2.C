/*
Slip 23-2
Write a C program to accept an infix expression, covert it into
its equivalent prefix expression and display the result.
*/


/* Size of Stack */

#define SIZE 50            
#include<string.h>
#include<ctype.h>
#include<stdio.h>

void strReverse(char* str);
char s[SIZE];
int top=-1;       /* Global Declarations */
 
void push(char elem)
{                       /* Function for PUSH operation */
    s[++top]=elem;
}

char pop()
{                      /* Function for POP operation */
    return(s[top--]);
}
 
int pr(char elem)
{                 /* Function for precedence */
    switch(elem)
    {
    	case '(': return 0;
    	case ')': return 1;
    	case '+':
    	case '-': return 2;
    	case '*':
    	case '/': return 3;
	case '^': return 4;
	case '$': return 5;
    }
}

void main()
{
    /* Main Program */
    char infx[50],prfx[50],ch,elem;
    int i=0,k=0;
    printf("\n\nRead the Infix Expression ?");
    scanf("%s",infx);
    push('(');
    strReverse(infx);
    while( (ch=infx[i++]) != '\0')
    {
	if( ch == ')')
		push(ch);
	else if(isalnum(ch))
		prfx[k++]=ch;
	else if( ch == '(')
	{
	     while( s[top] != ')')
		    prfx[k++]=pop();
	     elem=pop(); /* Remove ) */
	}
	else
	{
	     /* Operator */
	     while( pr(s[top]) >= pr(ch) )
		    prfx[k++]=pop();
	     push(ch);// (
	}
    }

    while( s[top] != '(')     /* Pop from stack till empty */
	prfx[k++]=pop();

    prfx[k]='\0';          /* Make prfx as valid string */
    strReverse(prfx);
    printf("\nPrefix Expression: %s\n\n",prfx);
}

void strReverse(char* str)
{
	    int length = strlen(str);
	    char temp;
	    int i,j;
	    for(i = 0, j = length-1;i < length/2; i++, j--)
	    {
		temp = str[i];
		str[i]=str[j];
		str[j] = temp;
	    }
	    return;
}
//C*B+A
//A+B*C  => +A*BC
//A+B*C/D  => +A*B/CD
//A/(B^C)+D  => +/A^BCD
//(A-B/C)*(D*E-F) => *-A/BC-*DEF
//(A*B+(C/D))-F  => -+*AB/CDF
//A/B^C-D   => -/A^BCD
//A+B*C/D   => +A*B/CD
//A+B+C+D   => +A+B+CD

/*
(A+B*C

Scanned char    stack      prefix
		  )
C		  )	     C
*		  )*	     C
B		  )*	     BC
+		  )+         *BC
A		  )+         A*BC
(		  -          +A*BC
*/		  


























