/* @author: mrinal-pandey
 * Demo of how a Doubly linked list is used in C using the following problem
 * Design, Develop and Implement a menu driven Program in C for the following operations 
 * on Doubly Linked List(DLL) of Employee Data with the fields:
 * SSN, Name, Dept, Designation, Sal, PhNo
 * a.Create a DLL of N Employees Data by using end insertion.
 * b.Display the status of DLL and count the number of nodes in it.
 * c.Perform Insertion and Deletion at End of DLL.
 * d.Perform Insertion and Deletion at Front of DLL.
 * e.Demonstrate how this DLL can be used as Double Ended Queue.
 * f.Exit
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct emp
{
	char ssn[10];
	char name[20];
	char dept[5];
	char desig[15];
	int salary;
	char phone[10];
	struct emp *rightLink;
	struct emp *leftLink;
}employee;

employee* createLinkedList(int);
void insertEnd(employee*);
void display(employee*);
employee* createNode();
employee* inputData();
employee* insertFront(employee*);
employee* deleteFront(employee*);
void deleteEnd(employee*);

int main()
{
	employee* firstNode;
	int numberBegin,choice,choiceQueue;
	char proceed,proceedQueue;

	printf("Enter the number of employees:");
	scanf("%d",&numberBegin);

	firstNode=createLinkedList(numberBegin);


	do
	{
		printf("\n1.Insert Front\n2.Insert End\n3.Delete Front\n4.Delete End\n5.Display\n6.Double ended queue\nEnter your choice:");
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
				if(firstNode==NULL)
				{
					printf("\nNothing to delete!\n");
				}
				else
				{
					firstNode=deleteFront(firstNode);
				}
				break;
			case 4:
				if(firstNode==NULL)
				{
					printf("\nNothing to delete!\n");
				}
				else
				{
					deleteEnd(firstNode);
				}
				break;
			case 5:
				if(firstNode==NULL)
				{
					printf("\nList is empty!\n");
				}
				else
				{
					display(firstNode);
				}
				break;
			case 6:
				do
				{
					printf("\n1.Insert End\n2.Insert Front\n3.Delete End\n4.Delete Front\nEnter your choice:");
					scanf("%d",&choiceQueue);
					switch(choiceQueue)
					{
						case 1:
							insertEnd(firstNode);
							break;
						case 2:
							firstNode=insertFront(firstNode);
							break;
						case 3:
							if(firstNode==NULL)
							{
								printf("\nNothing to delete!\n");
							}
							else
							{
								deleteEnd(firstNode);
							}
							break;
						case 4:
							if(firstNode==NULL)
							{
								printf("\nNothing to delete!\n");
							}
							else
							{
								firstNode=deleteFront(firstNode);
							}
							break;
					}

					printf("\nDo you want to continue in Queue(Y/N)?");
					scanf(" %c",&proceedQueue);
	
				}while(proceedQueue=='y'||proceedQueue=='Y');
				break;
		}

		printf("\nDo you want to continue with linked list(Y/N)?\n");
		scanf(" %c",&proceed);

	}while(proceed=='Y'||proceed=='y');

	return 0;
}

employee* deleteFront(employee* firstNode)
{
	employee* temp=firstNode;
	firstNode=firstNode->rightLink;

	printf("The employee data with SSN %s is deleted!\n",temp->ssn);
	free(temp);
	display(firstNode);
	return firstNode;

}

void deleteEnd(employee* firstNode)
{
	employee* temp=firstNode;
	while(temp->rightLink!=NULL)
	{
		temp=temp->rightLink;
	}
	(temp->leftLink)->rightLink=NULL;

	printf("\nThe employee data with SSN %s is deleted!\n",temp->ssn);
	free(temp);
	display(firstNode);
}

employee* insertFront(employee* firstNode)
{
	employee* newNode=inputData();

	newNode->rightLink=firstNode;
	firstNode->leftLink=newNode;
	firstNode=newNode;

	display(firstNode);

	return firstNode;
}

employee* createLinkedList(int number)
{
	employee* firstNode=NULL;
	employee* newNode;
	employee* temp;

	while(number--)
	{
		newNode=inputData();
		if(firstNode==NULL)
		{
			firstNode=newNode;
			temp=firstNode;
		}
		else
		{
			newNode->leftLink=temp;
			temp->rightLink=newNode;
			temp=newNode;
		}
	}

	display(firstNode);

	return firstNode;
}

void insertEnd(employee* firstNode)
{
	employee* temp=firstNode;
	employee *newNode=inputData();

	while(temp->rightLink!=NULL)
	{
		temp=temp->rightLink;
	}

	newNode->leftLink=temp;
	temp->rightLink=newNode;

	display(firstNode);

}

void display(employee *temp)
{
	int count=0;
	printf("NULL");
	while(temp!=NULL)
	{
		printf("<--[%s|%s|%s|%s|%d|%s]-->",temp->ssn,temp->name,temp->dept,temp->desig,temp->salary,temp->phone);
		temp=temp->rightLink;
		count++;
	}
	printf("NULL\n");
	printf("The number of nodes are %d\n",count);
}

employee* createNode()
{
	employee* temp=(employee*)malloc(sizeof(employee));
	temp->leftLink=NULL;
	temp->rightLink=NULL;
	return temp;
}

employee* inputData()
{
	employee* newNode=createNode();
	printf("\nEnter SSN:");
	scanf("%s",newNode->ssn);
	printf("Enter Name:");
	scanf("%s",newNode->name);
	printf("Enter Department:");
	scanf("%s",newNode->dept);
	printf("Enter Designation:");
	scanf("%s",newNode->desig);
	printf("Enter Salary:");
	scanf("%d",&(newNode->salary));
	printf("Enter Phone number:");
	scanf("%s",newNode->phone);
	return newNode;
}
