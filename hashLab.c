/* @author: mrinal-pandey
 * Given a File of N employee records with a set K of Keys(4-digit) which uniquely 
 * determine the records in file F. Assume that file F is maintained in memory by a HashTable(HT)
 * of m memory locations with L as the set of memory addresses(2-digit) of locations in HT.
 * Let the keys in K and addresses in L are Integers.
 * Design and develop a Program in C that uses Hash function H:K®L as H(K)=K mod m(remainder method),
 * and implement hashing technique to map a given key K to the address space L.
 * Resolve the collision(if any) using linear probing
 * */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct employee
{
	int id;
	char name[15];
}EMP;

int dataPresent[MAX];
EMP emp[MAX];

void display()
{
	int i;
	printf("\nHTKey\tEmpID\tName\n\n");
	for(i=0;i<MAX;i++)
	{
		if(dataPresent[i]!=-1)
		{
			printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
		}
	}
	printf("\n");
}

int keyGen(int data)
{
	return data%100;
}

int empDetail(int key)
{
	printf("\nEnter the ID:");
	scanf("%d",&emp[key].id);
	printf("Enter the name:");
	scanf("%s",emp[key].name);
	return key;
}

void linearProbing(int key)
{
	int flag=0, i, count=0;

	if(dataPresent[key]==-1)
	{
		dataPresent[key]=empDetail(key);
	}
	else
	{
		printf("\nCollision Detected!\n");

		for(i=0;i<MAX;i++)
		{
			if(dataPresent[i]!=-1)
			{
				count++;
			}
		}

		if(count==MAX)
		{
			printf("\nHash Table Full\n");
			exit(1);
		}

		printf("\nCollision Avoided using Linear Probing\n");

		for(i=key;i<MAX;i++)
		{
			if(dataPresent[i]==-1)
			{
				dataPresent[i]=empDetail(i);
				flag=1;
				break;
			}
		}

		for(i=0;i<key&&flag==0;i++)
		{
			if(dataPresent[i]==-1)
			{
				dataPresent[i]=empDetail(i);
				break;
			}
		}
	}
}

int main()
{
	int key, data, choice,i;

	for(i=0;i<MAX;i++)
	{
		dataPresent[i]=-1;
	}

	do
	{
		printf("\nEnter the data:");
		scanf("%d",&data);
		
		key=keyGen(data);
		linearProbing(key);
		
		printf("\nContinue?(1/0)\nDisplay(2)\n");
		scanf("%d",&choice);
		
		if(choice==2)
		{
			display();
			printf("Continue?(1/0)\nDisplay(2)\n");
			scanf("%d",&choice);
		}

	}while(choice);
	return 0;
}
