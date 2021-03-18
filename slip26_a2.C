/*
Slip 26-2
Write menu driven program using C for BST.
The menu includes-
	-Create
	-Traverse using Inorder technique
	-Search a given value
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
void inorder(struct node *);
struct node *search(struct node *, int);

void main()
{
	int ch, key;
	char ans='n';
	struct node *new_node, *temp;
	clrscr();

	do
	{
		printf("\n1. Create");
		printf("\n2. Traverse in Inorder");
		printf("\n3. Seacrh");
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
						insert(root,new_node);

					printf("\nDo you want to enter more elements (y/n) : ");
					ans=getch();
				}while(ans=='y');
				break;

			case 2 : if(root==NULL)
					printf("\nTree is not created");
				else
				{
					printf("\nInorder Display : ");
					inorder(root);
				}
				break;

			case 3 : printf("\nEnter element to search : ");
				scanf("%d",&key);

				temp=search(root,key);

				if(temp==NULL)
					printf("\nElement not present");
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

void inorder(struct node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lchild);
		printf("%d ",temp->data);
		inorder(temp->rchild);
	}
}//inorder

struct node *search(struct node *root, int key)
{
	struct node *tmp;
	tmp=root;

	while(tmp!=NULL)
	{
		if(tmp->data==key)
		{
			printf("\n%d element found",tmp->data);
			return tmp;
		}

		if(tmp->data>key)
			tmp=tmp->lchild;
		else
			tmp=tmp->rchild;
	}//while
	return NULL;
}//search

