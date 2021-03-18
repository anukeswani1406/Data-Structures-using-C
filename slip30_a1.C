/*
Slip 30-1
Write a C program to accept the details of employees from user
and display it on the screen using Dynamic Memory Allocation.
*/

     #include<stdio.h>
     #include<conio.h>
     #include<malloc.h>

     # define new (struct emp *)malloc(sizeof(struct emp))

     struct emp
     {
	int no;
	char name[20];
	struct emp*link;
     };

     struct emp *create()
     {
	  struct emp *h=NULL,*n,*t;
	  int i,m;
	  printf("Enter how many employees :");
	  scanf("%d",&m);
	  for(i=0;i<m;i++)
	  {
	    n=new; //Dynamic Memory Allocation

	/*  n=(struct emp *)malloc(sizeof(struct emp)); */
	    n->link=NULL;
	    printf("Enter number=");
	    scanf("%d",&n->no);
	    printf("Enter name=");
	    scanf("%s",&n->name);

	    if(h==NULL)
	       t=h=n;
	    else
	    {
	       t->link=n;
	       t=n;
	    }
	  }
	  return(h);
     }

     void display(struct emp *h)
     {
	  if(h!=NULL)
	  {
	     printf("\n------------------------------------------");
	     printf("\nNO= %d",h->no);
	     printf("\t\tNAME= %s",h->name);
	     display(h->link);
	  }
     }

     void main()
     {
       struct emp *e;
       clrscr();

       e=create();

       printf("\nDETAIL OF EMPLOYEE'S\n");

       display(e);
       getch();
     }

