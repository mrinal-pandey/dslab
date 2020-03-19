/* @author: mrinal-pandey
 * Demo of how a Circular queue is used in C using the following problem
 * Design, Develop and Implement a menu driven Program in C for the following operations
 * on Circular QUEUE of Characters(Array Implementation of Queue with maximum size MAX)
 * a.Insert an Element onto Circular QUEUE
 * b.Delete an Element from Circular QUEUE
 * c.Demonstrate Overflow and Underflow situations on Circular QUEUE
 * d.Display the status of Circular QUEUE
 * e.Exit 
 * Support the program with appropriate functions for each of the above operations
 * */

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

void insert(int[],int*,int*,int);
int delete(int[],int*,int*);
void display(int[],int*,int*,int);
void queueFull();
void queueEmpty();

int main()
{
	int queue[MAX],front=0,rear=0,count=0;
	int choice,deletedValue,value;
	char proceed;

	do{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Display status\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				if((rear+1)%MAX==front)
				{
					queueFull();
				}
				else
				{
					printf("\nEnter the value to insert:\n");
					scanf("%d",&value);
					insert(queue,&front,&rear,value);
					count++;
					display(queue,&front,&rear,count);
				}
				break;
			case 2:
				if(front==rear)
				{
					queueEmpty();
				}
				else
				{
					deletedValue=delete(queue,&front,&rear);
					printf("\nThe value you deleted is:%d",deletedValue);
					count--;
					display(queue,&front,&rear,count);
				}
				break;
			case 3:
				if(front==rear)
				{
					queueEmpty();
				}
				else
				{
					display(queue,&front,&rear,count);
				}
				break;
			case 4:
				printf("\nThe elements currently in Queue are %d\n",count);
				printf("The value of Front is %d\n",front);
				printf("The value of Rear is %d\n",rear);
				printf("Queue can still accomodate %d elements\n",MAX-count-1);
				break;
			case 5:
				printf("Exiting...");
				return 0;
				break;
			default: 
				printf("Please enter a valid input!");
		}

		printf("\nDo you want to continue?(Y/N):");
		scanf(" %c",&proceed);

	}while(proceed=='Y'||proceed=='y');

	return 0;
}

void insert(int queue[],int* front,int* rear,int value)
{
	*rear=(*rear+1)%MAX;
	queue[*rear]=value;
}

int delete(int queue[],int* front,int* rear)
{
	*front=(*front+1)%MAX;
	return queue[*front];
}

void display(int queue[],int* front,int* rear,int count)
{
	int f=*front,i;
	
	printf("\n");

	for(i=1;i<=count;i++)
	{
		printf("%d ",queue[(f+1)%MAX]);
		f++;
	}

	printf("\n");
}

void queueFull()
{
	printf("\nQueue Full!\n");
}

void queueEmpty()
{
	printf("\nQueue Empty!\n");
}
