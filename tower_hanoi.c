#include<stdio.h>

void hanoi(int,char,char,char);

int main()
{
	int num;
	printf("\nEnter the number of discs:");
	scanf("%d",&num);
	printf("\nThe tower of hanoi is as follows:\n");
	hanoi(num,'S','A','D');
	return(0);
}
void hanoi(int disc,char source,char aux,char dest)
{
	if(disc==1)
	{
		printf("Move %c to %c.\n",source,dest);
		return;
	}
	hanoi(disc-1,source,dest,aux);
	printf("Move %c to %c.\n",source,dest);
	hanoi(disc-1,aux,source,dest);
}	
