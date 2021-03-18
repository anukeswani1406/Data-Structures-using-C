/*
Slip 12-2
Write menu driven program using C for BST.
The menu includes-
	-Create
	-Insert element in a BST
	-Display
*/

#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *lchild, *rchild;
}*root=NULL;

struct node *get_node();
void create(struct node *, struct node *);
void insert(struct node *, struct node *);
void inorder(struct node *);

void main()
{
	int ch, key;
	char ans='n';
	struct node *new_node, *temp;
	clrscr();

	do
	{
		printf("\n1. Create");
		printf("\n2. Insert a node");
		printf("\n3. Display in Inorder");
		printf("\n4. Exit");

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
						create(root,new_node);

					printf("\nDo you want to enter more elements (y/n) : ");
					ans=getch();
				}while(ans=='y');
				break;

			case 2 : new_node=get_node();
				flushall();
				printf("Enter the element to insert : ");
				scanf("%d",&new_node->data);

				create(root,new_node);
				break;



			case 3 : if(root==NULL)
					printf("\nTree is not created");
				else
				{
					printf("\nInorder Display : ");
					inorder(root);
				}
				break;

			case 4 : exit(0);
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

void create(struct node *root, struct node *new_node)
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
}//create

void inorder(struct node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lchild);
		printf("%d ",temp->data);
		inorder(temp->rchild);
	}
}//inorder

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
