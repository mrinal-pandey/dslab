/* @author: mrinal-pandey
 * Demo of graph in C using the following problem
 * Design, Develop and Implement a Program in C for the following operations on Graph(G) of Cities
 * a. Create a Graph of N cities using Adjacency Matrix.
 * b. Print all the nodes reachable from a given starting node in a digraph using BFS method
 * c. Check whether a given graph is connected or not using DFS method.
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int** createGraph(int);
int* bfs(int**, int, int);
int* dfs(int**, int, int);

int* bfs(int **graph, int begin, int N)
{	
	int i,queue[100],rear,front,j;
	int *visited=(int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++)
	{
		visited[i]=0;
	}
	rear=-1;

	queue[++rear]=begin;

	front=rear;

	visited[begin]=1;

	while(front<=rear)
	{
		begin=queue[front++];
	
		for(i=0;i<N;i++)
		{
			if(graph[begin][i]==1&&visited[i]==0)
			{
				visited[i]=1;
				queue[++rear]=i;
			}
		}
	}

	return visited;
}

int* dfs(int **graph, int begin, int N)
{	
	int i,stack[100],top,j;
	int *visited=(int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++)
	{
		visited[i]=0;
	}
	top=-1;

	stack[++top]=begin;

	visited[begin]=1;

	while(top!=-1)
	{
		begin=stack[top--];
	
		for(i=0;i<N;i++)
		{
			if(graph[begin][i]==1&&visited[i]==0)
			{
				visited[i]=1;
				stack[++top]=i;
			}
		}
	}

	return visited;
}

int main()
{
	int N,choice,beginNode,i,j,flag=0;
	char proceed;
	int **cities,*visited;

	printf("Enter the number of cities:");
	scanf("%d",&N);

	cities=createGraph(N);

	do
	{
		printf("\n1.Get all the nodes reachable\n2.Check graph is connected or not\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the node:");
				scanf("%d",&beginNode);
				visited=bfs(cities, beginNode, N);	
				for(i=0;i<N;i++)
				{
					if(visited[i]==1)
					{
						printf("%d ",i);
					}
				}
				printf("\n");
				break;
			case 2:
				for(i=0;i<N;i++)
				{
					visited=dfs(cities, i, N);
					for(j=0;j<N;j++)
					{
						if(visited[j]==0)
						{
							flag=1;
							break;
						}
					}
				}
				if(flag==1)
				{
					printf("\nDisconnected\n");
				}
				else
				{
					printf("\nConnected\n");
				}
				break;
			default:
				printf("\nInvalid option!\n");
		}

		printf("\nDo you want to proceed(Y/N)?");
		scanf(" %c",&proceed);
	}while(proceed=='y'||proceed=='Y');
	return 0;
}

int** createGraph(int N)
{
	int **cities,i,j;

	cities=(int**)malloc(N*sizeof(int*));
	for(i=0;i<N;i++)
	{
		*(cities+i)=(int*)malloc(N*sizeof(int));
	}

	printf("\nEnter adjacency matrix:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",(*(cities+i)+j));
		}
	}

	return cities;
}
