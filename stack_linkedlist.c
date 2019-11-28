#include<stdio.h>
#include<stdlib.h>

struct stk
{
	int info;
	struct stk *next;
};

void push(struct stk **,int);
int pop(struct stk **);
int top_element(struct stk *);

int main()
{
	struct stk *top=NULL;
	int ch,n,item;
	while(1)
	{
		printf("\n1. Push\n2. Pop\n3. Top element\n0. Exit\n\nChoice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the item to be pushed:");
				scanf("%d",&item);
				push(&top,item);
				break;
			case 2: item=pop(&top);
				if(item!=-9999)
				{
					printf("\nThe deleted item is:%d",item);
				}
				break;
			case 3: n=top_element(top);
				if(n!=-9999)
					printf("The top element is:%d",n);
				break;
			case 0: exit(0);
			default: printf("\nWrong choice!!");
		}
	}
	return(0);
}
void push(struct stk **ptop,int item)
{
	struct stk *newnode;
	newnode=(struct stk *)malloc(sizeof(struct stk));
	newnode->info=item;
	newnode->next=*ptop;
	*ptop=newnode;
}
int pop(struct stk **ptop)
{	
	struct stk *temp;
	int item;
	if(*ptop==NULL)
	{
		printf("\nUnderflow");
		return(-9999);
	}
	item=(*ptop)->info;
	temp=*ptop;
	*ptop=temp->next;
	temp->next=NULL;
	free(temp);
	return(item);
}
int top_element(struct stk *top)
{
	if(top==NULL)
	{
		printf("\nUnderflow\t");
		return(-9999);
	}
	else
	{
		return(top->info);
	}
}















	
