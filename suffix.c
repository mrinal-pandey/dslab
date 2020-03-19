/* @author: mrinal-pandey
 * Design, Develop and Implement a Program in C for the following Stack Application
 * Evaluation of Suffix expression with single digit operands and operators: +, -, *, /
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void push(int[],int*,int);
int pop(int[],int*);
void operate(char[]);
int validate(char[]);

int main()
{
	char postfix[30];
	int valid;
	
	do
	{
		printf("\nEnter your postfix expression:\n");
		scanf("%s",postfix);

		valid=validate(postfix);
		if(valid==0)
		{
			printf("\nInvalid expression!\nPlease enter a valid one!\n");
		}

	}while(valid!=1);

	operate(postfix);

	return 0;
}

int validate(char testExp[])
{
	int i,countOperators=0,countOperands=0;
	for(i=0;i<strlen(testExp);i++)
	{
		if(isalnum(testExp[i]))
		{
			countOperands++;
		}
		else
		{
			switch(testExp[i])
			{
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
					countOperators++;
					break;
				default:
					return 0;
			}
		}
	}

	if(countOperators!=countOperands-1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void operate(char postfix[])
{
	int stack[30],popA,popB,resultPop,i,TOP=-1;
	char characterScanned;
	
	for(i=0;i<strlen(postfix);i++)
	{
		characterScanned=postfix[i];
		if(isdigit(characterScanned))
		{
			push(stack,&TOP,characterScanned-'0');
		}
		else
		{
			popA=pop(stack,&TOP);
			popB=pop(stack,&TOP);
			switch(characterScanned)
			{
				case '+':
					resultPop=popA+popB;
					break;
				case '-':
					resultPop=popB-popA;
					break;
				case '*':
					resultPop=popA*popB;
					break;
				case '/':
					resultPop=popB/popA;
					break;
				case '^':
					resultPop=(int)pow(popB,popA);
					break;
			}
			push(stack,&TOP,resultPop);
		}
	}

	printf("\nThe answer is:%d\n\n",stack[TOP]);
}

void push(int stack[],int *TOP,int value)
{
	*TOP=*TOP+1;
	stack[*TOP]=value;
}

int pop(int stack[],int *TOP)
{
	*TOP=*TOP-1;
	return stack[*TOP+1];
}
