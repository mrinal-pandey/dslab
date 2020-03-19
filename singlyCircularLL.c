/* @author: mrinal-pandey
 * Design, Develop and Implement a Program in C for the following operations on Singly Circular
 * Linked List(SCLL) with header nodes
 * a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5+3x3yz+2xy5z-2xyz3
 * b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the
 * result in POLYSUM(x,y,z)
 * Support the program with appropriate functions for each of the above operations.
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct poly
{
	int coeff;
	int expox;
	int expoy;
	int expoz;
	struct poly *next;
}polynomial;

polynomial* createPolynomial();
polynomial* createTerm();
void insertEnd(polynomial*, polynomial*);
void display(polynomial*, polynomial*);
polynomial* inputData();
polynomial* addPolynomial(polynomial*, polynomial*);
int compare(polynomial*, polynomial*);
void attach(polynomial*, int, int, int, int);
void evaluate();
polynomial* addPolynomial(polynomial*, polynomial*);

int main()
{
	int choice;
	char proceed;
	polynomial *polyA;
	polynomial *polyB;
	polynomial *sumAB;
	polynomial *headerA;
	polynomial *headerB;

	do
	{
		printf("1.Evaluate polynomial\n2.Add two polynomials\nEnter your choice:");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				evaluate();
				break;

			case 2:
				printf("\nEnter Polynomials in decreasing order of degrees!\n");

				headerA=createTerm();
				headerB=createTerm();

				polyA=createPolynomial(headerA);
				polyB=createPolynomial(headerB);

				printf("\nPolynomial A:\n");
				display(polyA, headerA);
				printf("\nPolynomial B:\n");
				display(polyB, headerB);

				sumAB=addPolynomial(headerA, headerB);
				printf("\nThe resulting polynomial is :\n");
				display(sumAB->next, sumAB);
				printf("\n");
				break;
		}

		printf("\nDo you want to continue(Y/N)?");
		scanf(" %c",&proceed);
	}while(proceed=='y'||proceed=='Y');

	return 0;
}

void evaluate()
{
	polynomial* headerToEval;
	polynomial* toEval;
	polynomial* newTerm;
	int x,y,z;
	double sum=0;
	
	printf("\nEnter value of x:");
	scanf("%d",&x);
	printf("Enter value of y:");
	scanf("%d",&y);
	printf("Enter value of z:");
	scanf("%d",&z);
	
	headerToEval=createTerm();
	toEval=createPolynomial(headerToEval);

	display(toEval, headerToEval);

	while(toEval!=headerToEval)
	{
		sum=sum+(toEval->coeff)*(pow(x,(toEval->expox)))*(pow(y,(toEval->expoy)))*(pow(z,(toEval->expoz)));
		toEval=toEval->next;
	}

	printf("\nThe evaluated value is:%f",sum);
}

polynomial* addPolynomial(polynomial* headerA, polynomial* headerB)
{
	polynomial* termA=headerA->next;
	polynomial* termB=headerB->next;
	polynomial* headerSum=createTerm();
	headerSum->next=headerSum;
	
	while(termA!=headerA&&termB!=headerB)
	{
		switch(compare(termA, termB))
		{
			case 0:
				attach(headerSum, termA->coeff+termB->coeff, termA->expox, termA->expoy, termA->expoz);
				termA=termA->next;
				termB=termB->next;
				break;
			case 1:
				attach(headerSum, termA->coeff, termA->expox, termA->expoy, termA->expoz);
				termA=termA->next;
				break;
			case -1:
				attach(headerSum, termB->coeff, termB->expox, termB->expoy, termB->expoz);
				termB=termB->next;
				break;
			case 2:
				attach(headerSum, termA->coeff, termA->expox, termA->expoy, termA->expoz);
				attach(headerSum, termB->coeff, termB->expox, termB->expoy, termB->expoz);
				termA=termA->next;
				termB=termB->next;
				break;
		}
	}

	for(;termA!=headerA;)
	{
		attach(headerSum, termA->coeff, termA->expox, termA->expoy, termA->expoz);
		termA=termA->next;
	}
	for(;termB!=headerB;)
	{
		attach(headerSum, termB->coeff, termB->expox, termB->expoy, termB->expoz);
		termB=termB->next;
	}

	return headerSum;
}

void attach(polynomial* header, int coeff, int expoX, int expoY, int expoZ)
{
	polynomial* newTerm=createTerm();
	polynomial* term=header;
	newTerm->coeff=coeff;
	newTerm->expox=expoX;
	newTerm->expoy=expoY;
	newTerm->expoz=expoZ;
	while(term->next!=header)
	{
		term=term->next;
	}
	term->next=newTerm;
	newTerm->next=header;
}

int compare(polynomial* termA, polynomial* termB)
{
	int degreeA, degreeB;
	if(termA->expox==termB->expox&&termA->expoy==termB->expoy&&termA->expoz==termB->expoz)
	{
		return 0;
	}
	else
	{
		degreeA=termA->expox+termA->expoy+termA->expoz;
		degreeB=termB->expox+termB->expoy+termB->expoz;

		if(degreeA==degreeB)
		{
			return 2;
		}
		else if(degreeA>degreeB)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}

void display(polynomial* term, polynomial* header)
{
	printf("[%p]<--",header);
	while(term!=header)
	{
		printf("[%d|%d|%d|%d][%p]-->",(term->coeff),(term->expox),(term->expoy),(term->expoz),(term->next));
		term=term->next;
	}
	printf("[%p]\n",header);
}

void insertEnd(polynomial *firstTerm, polynomial *header)
{
	polynomial* newTerm=inputData();
	polynomial* term;
	term=firstTerm;

	while(term->next!=header)
	{
		term=term->next;
	}

	term->next=newTerm;
	newTerm->next=header;
}

polynomial* createTerm()
{
	polynomial* term=(polynomial*)malloc(sizeof(polynomial));
	term->next=NULL;
	return term;
}

polynomial* inputData()
{
	polynomial* newTerm=createTerm();
	printf("\nEnter the coefficient:");
	scanf("%d",&(newTerm->coeff));
	printf("Enter the exponent of x:");
	scanf("%d",&(newTerm->expox));
	printf("Enter the exponent of y:");
	scanf("%d",&(newTerm->expoy));
	printf("Enter the exponent of z:");
	scanf("%d",&(newTerm->expoz));
	return newTerm;
}

polynomial* createPolynomial(polynomial *header)
{
	int N;
	polynomial* firstTerm;

	printf("\nEnter the number of terms of the polynomial:");
	scanf("%d",&N);

	firstTerm=inputData();
	header->next=firstTerm;
	firstTerm->next=header;

	while(N--!=1)
	{
		insertEnd(firstTerm, header);
	}

	return firstTerm;
}
