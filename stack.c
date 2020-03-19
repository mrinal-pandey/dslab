/* @author: mrinal-pandey
 * Design, Develop and Implement a menu driven Program in C for the following operations on
 * STACK of Integers(Array Implementation of Stack with maximum size MAX)
 * a. Push an Element onto Stack
 * b. Pop an Element from Stack
 * c. Demonstrate how Stack can be used to check Palindrome
 * d. Demonstrate Overflow and Underflow situations on Stack
 * e. Display the status of Stack
 * f. Exit
 * Support the program with appropriate functions for each ofthe above operations
 * */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX 50

pid_t id;
void push(int[],int*,int);
int pop(int[],int*);
void display(int[],int*);
void palindrome(int[],int*);

void sigHandler() {
	printf("Nothing to do with this!!\n");
}

int main()
{
	int stat;
	int choice;
	char repeat;
	int popValue;
	int value;
	srand(time(NULL));
	int multipushNumber,multipopNumber;
	int stack[MAX];
	int TOP=-1;

	do
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Check for palindrome\n5.Multipush\n6.Multipop\n7.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(TOP>MAX)
				{
					printf("\nStack is full\n");
				}
				else
				{
					//printf("\nEnter the value to be pushed:");
					//scanf("%d",&value);
					value=rand()%100;
					push(stack,&TOP,value);
					display(stack,&TOP);
				}
				break;
			case 2:
				if(TOP==-1)
				{
					printf("\nStack is empty\n");
				}
				else
				{
					popValue=pop(stack,&TOP);
					printf("\nThe value popped is:%d\n",popValue);
					display(stack,&TOP);
				}
				break;
			case 3:
				if(TOP==-1)
				{
					printf("\nStack is empty\n");
				}
				else
				{
					display(stack,&TOP);
				}
				break;
			case 4:
				if(TOP==-1)
				{
					printf("\nStack is empty\n");
				}
				else if(TOP==0)
				{
					printf("\nPalindrome\n");
				}
				else if(TOP==1)
				{
					if(stack[0]==stack[1])
					{
						printf("\nPalindrome\n");
					}
					else
					{
						printf("\nNot Palindrome\n");
					}
				}
				else
				{
					palindrome(stack,&TOP);
				}
				break;
			case 5:
				if(TOP+1>=MAX)
				{
					printf("\nStack is full\n");
				}
				else
				{
					//printf("\nEnter the number of elements to push:");
					do
					{
						multipushNumber=rand()%50;
					}while(multipushNumber+TOP+1>MAX);
					//scanf("%d",&multipushNumber);
					printf("Proces ID is:%d\n",getpid());
					if((id = fork()) != -1) {
						printf("Proces ID is:%d\n",getpid());
						printf("\nPushing on the stack...");
						while(multipushNumber--)
						{
							//printf("\nEnter value to push:");
							//scanf("%d",&value);
							value=rand()%100;
							push(stack,&TOP,value);
						}
						sleep(20);
					}
					else {
							printf("Error!!\n");
					}
					wait(&stat);
					sleep(30);
					display(stack,&TOP);
				}
				break;
			case 6:
				if(TOP==-1)
				{
					printf("\nStack is empty\n");
				}
				else
				{
					//printf("\nEnter the number of elements to pop:");
					//scanf("%d",&multipopNumber);
					do
					{
						multipopNumber=rand()%50;
					}while(multipopNumber>TOP+1);
					if(multipopNumber>TOP+1)
					{
						printf("\nCan't pop elements more than the elements present");
					}
					else
					{
						printf("\nPopping from the stack...");
						sleep(3);
						while(multipopNumber--)
						{	
							popValue=pop(stack,&TOP);
							printf("\nThe value popped is %d\n",popValue);
						}
					}
					display(stack,&TOP);
				}
				break;	
			case 7:
				printf("\nExiting...\n");
				return 0;
			default:
				printf("\nEnter a valid input\n");
		}
		printf("\nDo you want to continue?(Y/N):");
		scanf(" %c",&repeat);

	}while(repeat=='y'||repeat=='Y');
	return 0;
}

void push(int stack[],int* TOP,int value)
{
	*TOP=*TOP+1;
	stack[*TOP]=value;
}

int pop(int stack[],int* TOP)
{
	*TOP=*TOP-1;
	return stack[*TOP+1];
}

void display(int stack[],int* TOP)
{
	int i;
	for(i=0;i<=*TOP;i++)
	{
		printf("%d ",stack[i]);
	}
}

void palindrome(int stack[],int* TOP)
{
	int copyTOP=*TOP;
	int i,popValue,count=-1;
	
	for(i=0;i<=(*TOP)/2;i++)
	{
		popValue=pop(stack,&copyTOP);
		if(popValue==stack[i])
		{
			count++;
		}
		else
		{
			break;
		}
	}

	if(count==(*TOP)/2)
	{
		printf("\nPalindrome\n");
	}
	else
	{
		printf("\nNot Palindrome");
	}
}

