/*
Slip 23-1
Write a C program to create BST and display its leaf nodes.
*/

#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *lchild, *rchild;
}*root=NULL;

struct node *get_node();
void insert(struct node *, struct node *);
void display(struct node *);

void main()
{
	int ch, key;
	char ans='n';
	struct node *new_node, *temp;
	clrscr();

	do
	{
		printf("\n1. Create");
		printf("\n2. Display the Leaf Nodes");
		printf("\n3. Exit");

		printf("\nEnter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1 : do
				{
					new_node=get_node();
					flushall();
					printf("\nEnter the element : ");
					scanf("%d",&new_node->data);

					if(root==NULL)
						root=new_node;
					else
						insert(root,new_node);

					printf("\nDo you want to enter more elements (y/n) : ");
					ans=getch();
				}while(ans=='y');
				break;

			case 2 : if(root==NULL)
					printf("\nTree is not created");
				else
				{
					printf("\nDisplay : ");
					display(root);
				}
				break;

			case 3 : exit(0);
		}//switch
	}while(ch<4);
}//main

struct node *get_node()
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	return tmp;
}//get_node

void insert(struct node *root, struct node *new_node)
{
	if(new_node->data < root->data)
	{
		if(root->lchild==NULL)
			root->lchild=new_node;
		else
			insert(root->lchild, new_node);
	}//if

	if(new_node->data > root->data)
	{
		if(root->rchild==NULL)
			root->rchild=new_node;
		else
			insert(root->rchild, new_node);
	}//if
}//insert

void display(struct node *temp)
{
	if(temp!=NULL)
	{
		if(temp->lchild==NULL && temp->rchild==NULL)
			printf("%d ",temp->data);
		display(temp->lchild);
		display(temp->rchild);
	}
}//display