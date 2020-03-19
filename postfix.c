/* @author: mrinal-pandey
 * Design, Develop and Implement a Program in C for converting an Infix Expression to Postfix
 * Expression. Program should support for both parenthesized and free parenthesized expressions with
 * the operators: +, -, *, /, %(Remainder), ^(Power) and alphanumeric operands.
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void push(char[],int*,char);
char pop(char[],int*);
void convert(char[]);
int checkValidity(char[]);

int main()
{
	char infix[100];
	int validity;

	do
	{
		printf("\nEnter your infix expression:\n");
		scanf("%s",infix);
	
		validity=checkValidity(infix);

		if(validity)
		{
			convert(infix);
		}
		else
		{
			printf("\nNot a valid expression!\nTry again!\n");
		}

	}while(validity!=1);

	return 0;
}

int checkValidity(char testExp[])
{
	int i=0,countRight=0,countLeft=0,variableFlag=1,operatorFlag=1,bracesFlag=1;
	int testStackTOP=-1;
	char testStack[100];

	for(i=0;i<strlen(testExp);i++)
	{
		if(isdigit(testExp[i]))
		{
			if(isalpha(testExp[i+1]))
			{
				variableFlag=0;
			}
		}
	}

	for(i=0;i<strlen(testExp);i++)
	{
		switch(testExp[i])
		{
			case '+':
			case '-':
			case '/':
			case '*':
			case '%':
			case '^':
				switch(testExp[i-1])
				{
					case '+':
					case '-':
					case '*':
					case '/':
					case '%':
					case '^':
					case '(':
						operatorFlag=0;
						break;
				}
				switch(testExp[i+1])
				{
					case '+':
					case '-':
					case '*':
					case '/':
					case '%':
					case '^':
					case ')':
						operatorFlag=0;
						break;
				}
				break;
		}
	}	

	for(i=0;i<strlen(testExp);i++)
	{
		if(testExp[i]=='(')
		{
			if(testExp[i-1]==')')
			{
				bracesFlag=0;
				break;
			}
			countLeft++;
		}
		else if(testExp[i]==')')
		{
			if(testExp[i+1]=='(')
			{
				bracesFlag=0;
				break;
			}
			countRight++;	
		}
		else
		{
			push(testStack,&testStackTOP,testExp[i]);
		}
	}

	if(countLeft==countRight&&bracesFlag)
	{
		if(testStackTOP==-1)
		{
			bracesFlag=0;
		}
	}

	if(bracesFlag&&variableFlag&&operatorFlag)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void convert(char infix[])
{

	char postfix[100],stack[100],scannedCharacter,popChar;
	int i=0,j,stackTOP=-1,postfixTOP=-1;	

	while(i<strlen(infix))
	{
		scannedCharacter=infix[i];

		if(isalnum(scannedCharacter)||scannedCharacter=='_')
		{
			push(postfix,&postfixTOP,scannedCharacter);
		}
		else if(scannedCharacter=='^')
		{
			push(stack,&stackTOP,scannedCharacter);
		}
		else
		{
			switch(scannedCharacter)
			{
				case '(':
					push(stack,&stackTOP,scannedCharacter);
					break;
				case ')':
					while(stack[stackTOP]!='(')
					{
						popChar=pop(stack,&stackTOP);
						push(postfix,&postfixTOP,popChar);
					}
					stackTOP--;
					break;	
			}

			if(scannedCharacter=='+'||scannedCharacter=='-')
			{
				while(stack[stackTOP]=='+'||stack[stackTOP]=='-'||stack[stackTOP]=='/'||stack[stackTOP]=='*'||stack[stackTOP]=='%'||stack[stackTOP]=='^')
				{
					popChar=pop(stack,&stackTOP);
					push(postfix,&postfixTOP,popChar);
				}
				push(stack,&stackTOP,scannedCharacter);
			}

			if(scannedCharacter=='*'||scannedCharacter=='/'||scannedCharacter=='%')
			{
				while(stack[stackTOP]=='^'||stack[stackTOP]=='*'||stack[stackTOP]=='/'||stack[stackTOP]=='%')
				{
					popChar=pop(stack,&stackTOP);
					push(postfix,&postfixTOP,popChar);
				}
				push(stack,&stackTOP,scannedCharacter);
			}

		}
		
		i++;
	}
	
	while(stackTOP!=-1)
	{
		popChar=pop(stack,&stackTOP);
		push(postfix,&postfixTOP,popChar);
	}

	postfix[postfixTOP+1]='\0';

	printf("\nPostfix expression is:\n");

	for(j=0;postfix[j]!='\0';j++)
		printf("%c",postfix[j]);

	printf("\n\n");
}

void push(char stack[],int *TOP,char scanned)
{
	stack[*TOP+1]=scanned;
	*TOP=*TOP+1;
}

char pop(char stack[],int *TOP)
{
	*TOP=*TOP-1;
	return stack[*TOP+1];
}
