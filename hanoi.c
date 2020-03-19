/* @author: mrinal-pandey
 * Design, Develop and Implement a Program in C for the following Stack Application
 * Solving Tower of Hanoi problem with n disks
 * */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void tower(int,char,char,char);

int main()
{
	int N;
	printf("\nEnter the number of discs:");
	scanf("%d",&N);
	printf("\n");
	tower(N,'S','A','D');
	printf("\nTotal number of steps required are %d\n\n",(int)pow(2,N)-1);
	return 0;
}

void tower(int N,char source,char aux,char dest)
{
	if(N==1)
	{
		printf("Move %d from %c to %c\n",N,source,dest);
		return;
	}
	tower(N-1,source,dest,aux);
	printf("Move %d from %c to %c\n",N,source,dest);
	tower(N-1,aux,source,dest);
}
