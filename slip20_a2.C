/*
Slip 20-2
Write a C Program to create BST, traverse it using
recursive operations like inorder, Preorder and postorder
and display the result of each one separately.
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
void preorder(struct node *);
void postorder(struct node *);

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
		printf("\n3. Traverse in Preorder");
		printf("\n4. Traverse in Postorder");
		printf("\n5. Exit");

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

			case 3 :if(root==NULL)
					printf("\nTree is not created");
				else
				{
					printf("\nPreorder Display : ");
					preorder(root);
				}
				break;

			case 4 :if(root==NULL)
					printf("\nTree is not created");
				else
				{
					printf("\nPostorder Display : ");
					postorder(root);
				}
				break;

			case 5 : exit(0);
		}//switch
	}while(ch<6);
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

void preorder(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("%d ",temp->data);
		preorder(temp->lchild);
		preorder(temp->rchild);
	}
}//preorder

void postorder(struct node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lchild);
		postorder(temp->rchild);
		printf("%d ",temp->data);
	}
}//postorder