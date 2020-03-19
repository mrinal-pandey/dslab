/* @author: mrinal-pandey
 * Demo of singly linked list in C using following problem 
 * Design, Develop and Implement a menu driven Program in C for the following operations on
 * Singly Linked List(SLL) of Student Data with the fields: USN, Name, Branch, Sem, PhNo
 * a.Create aSLLofNStudents Data by usingfrontinsertion.b.Displaythestatus ofSLLand countthe number ofnodes init c.PerformInsertionandDeletionatEnd ofSLLd.PerformInsertionandDeletionatFrontofSLLe.DemonstratehowthisSLLcan beusedasSTACKand QUEUEf.Exit
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Stud
{
	char name[20];
	char usn[10];
	char branch[3];
	int sem;
	char phone[10];
	struct Stud *nextNode;
}student;

student* createLinkList(int);
void display(student*);
student* createNode();
student* inputData();
void insertEnd(student*);
student* insertFront(student*);
void insertAt(student*,int);
student* deleteFront(student*);
void deleteEnd(student*);
void searchAndDelete(student*,char[]);

int main()
{
	int N,choice,position,stackOption,queueOption,numberOfNodes=0;
	char proceed,key[10],stackChoice,queueChoice;
	student *firstNode=NULL;
	student* temp;
	printf("Enter the number of students:");
	scanf("%d",&N);
	printf("\n");
	
	firstNode=createLinkList(N);

	do
	{
		printf("\n1.Insert Front\n2.Insert End\n3.Insert at 'N' position\n5.Delete at front\n6.Delete at end\n7.Display data\n8.Stack implementation\n9.Queue implementation\nEnter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				firstNode=insertFront(firstNode);
				break;
			case 2:
				insertEnd(firstNode);
				break;
			case 3:
				temp=firstNode;
				while(temp!=NULL)
				{
					temp=temp->nextNode;
					numberOfNodes++;
				}
				printf("\nEnter the position to insert:");
				scanf("%d",&position);
				if(position>numberOfNodes)
				{
					printf("\nPosition doesn't exist!\n");
				}
				else
				{
					insertAt(firstNode,position);
				}
				break;
			case 4:
				printf("\nEnter the USN to be searched:");
				scanf("%s",key);
				searchAndDelete(firstNode,key);
				break;
			case 5:
				if(firstNode==NULL)
				{
					printf("\nList is empty!\n");
				}
				else
				{
					firstNode=deleteFront(firstNode);
				}
				break;
			case 6:
				if(firstNode==NULL)
				{
					printf("\nList is empty\n");
				}
				else
				{
					deleteEnd(firstNode);
				}
				break;
			case 7:
				if(firstNode==NULL)
				{
					printf("\nNothing to display!\n");
				}
				else
				{
					display(firstNode);
				}
				break;
			case 8:
				do
				{
					printf("\n1.Push\n2.Pop\n3.Display\nEnter your choice:");
					scanf("%d",&stackOption);

					switch(stackOption)
					{
						case 1:
							insertEnd(firstNode);
							break;
						case 2:
							if(firstNode==NULL)
							{
								printf("\nList is empty\n");
							}
							else
							{
								deleteEnd(firstNode);
							}
							break;
						case 3:
							display(firstNode);
							break;
					}

					printf("\nDo you want to continue with stack(Y/N)?\n");
					scanf(" %c",&stackChoice);

				}while(stackChoice=='Y'||stackChoice=='y');

				break;
			case 9:
				do
				{
					printf("\n1.Insert\n2.Delete\n3.Display\nEnter your choice:");
					scanf("%d",&queueOption);

					switch(queueOption)
					{
						case 1:
							insertEnd(firstNode);
							break;
						case 2:
							if(firstNode==NULL)
							{
								printf("\nList is empty\n");
							}
							else
							{
								firstNode=deleteFront(firstNode);
							}
							break;
						case 3:
							display(firstNode);
					}

					printf("\nDo you want to continue with queue(Y/N)?\n");
					scanf(" %c",&queueChoice);

				}while(queueChoice=='Y'||queueChoice=='y');
				break;
		}
		
		printf("Do you wish to continue with linked list?(Y/N)\n");
		scanf(" %c",&proceed);
	}while(proceed=='y'||proceed=='Y');

	return 0;
}

void deleteEnd(student* firstNode)
{
	student* last=firstNode;
	student* previous=NULL;
	student* temp;

	while(last->nextNode!=NULL)
	{
		previous=last;
		last=last->nextNode;
	}

	temp=last;
	previous->nextNode=NULL;

	printf("\nDeleted data is of student with USN %s\n",temp->usn);
	display(firstNode);
	free(temp);
}

student* deleteFront(student* firstNode)
{

	student* temp;

	temp=firstNode;
	firstNode=firstNode->nextNode;

	printf("\nThe student with USN %s is removed\n",temp->usn);
	display(firstNode);

	free(temp);
	return firstNode;
}

void searchAndDelete(student *firstNode,char key[])
{
	student* current=firstNode;
	student* previous=NULL;
	student* temp;
	char choice;

	while(current!=NULL)
	{
		previous=current;
		if(strcmp(current->usn,key))
		{
			printf("\nStudent with USN %s is found\nDo you want to delete the data for the student(Y/N)?",current->usn);
			scanf("%c",&choice);
		}
		current=current->nextNode;
	}

}

student* createLinkList(int N)
{
	int i;
	student *newNode;
	student *firstNode;
	
	firstNode=NULL;

	for(i=1;i<=N;i++)
	{
		newNode=inputData();
		if(firstNode==NULL)
		{
			firstNode=newNode;
			firstNode->nextNode=NULL;
		}
		else
		{
			newNode->nextNode=firstNode;
			firstNode=newNode;
		}
	}

	display(firstNode);
	return firstNode;

}

void insertAt(student *firstNode,int position)
{
	int i;
	student *newNode=inputData();
	student *temp=firstNode;
	for(i=0;i<position-2;i++)
	{
		temp=temp->nextNode;
	}

	newNode->nextNode=temp->nextNode;
	temp->nextNode=newNode;
	display(firstNode);
}

student* insertFront(student *firstNode)
{	
	student *newNode=inputData();	
	
	if(firstNode==NULL)
	{
		firstNode=newNode;
		firstNode->nextNode=NULL;
	}
	else
	{
		newNode->nextNode=firstNode;
		firstNode=newNode;
	}

	display(firstNode);
	return firstNode;
}

void insertEnd(student *firstNode)
{
	student *newNode=inputData();
	student *temp=firstNode;
	
	while(temp->nextNode!=NULL)
	{
		temp=temp->nextNode;
	}

	temp->nextNode=newNode;

	display(firstNode);
}

void display(student *temp)
{
	int count=0;
	while(temp!=NULL)
	{
		printf("[%s|%s|%s|%d|%s]--->",temp->name,temp->usn,temp->branch,temp->sem,temp->phone);
		temp=temp->nextNode;
		count++;
	}
	printf("NULL\n");
	printf("Total number of students present are:%d\n",count);
}

student* createNode()
{
	student *temp=(student*)malloc(sizeof(student));
	temp->nextNode=NULL;
	return temp;
}

student* inputData()
{
	student *temp=createNode();
	printf("Enter the name of student:");
	scanf("%s",temp->name);
	printf("Enter the USN of student:");
	scanf("%s",temp->usn);
	printf("Enter the Branch of student:");
	scanf("%s",temp->branch);
	printf("Enter the Semester of student:");
	scanf("%d",&(temp->sem));
	printf("Enter the Phone number of student:");
	scanf("%s",temp->phone);
	printf("\n");
	return temp;
}
