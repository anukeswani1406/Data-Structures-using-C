/*
Slip 10-1
Write a C program to count indegree and outdegree of each node in graph.
*/

#include<stdio.h>
#include<conio.h>
void main()
{
	int m[10][10], r, c, sumin, sumout, i, j, n;
	clrscr();

	printf("\nEnter the number of vertices : ");
	scanf("%d",&n);

	for(r=0;r<n;r++)
	{
		for(c=0;c<n;c++)
		{
			m[r][c]=0;
			if(r!=c)
			{
				printf("\nIs there an edge between %d and %d : ",r+1,c+1);
				scanf("%d",&m[r][c]);
			}
		}
	}

	printf("\nVertices Indegree Outdegree Total");

	for(i=0;i<n;i++)
	{
		sumin=0;
		sumout=0;
		for(j=0;j<n;j++)
		{
		sumin=sumin+m[j][i];
		sumout=sumout+m[i][j];
		}
	}

	printf("\n%d \t%d \t%d \t%d",i+1,sumin,sumout,sumin+sumout);

	getch();
}