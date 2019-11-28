#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 5

typedef struct stk
{
	int arr[STACKSIZE];
	int top;
}stack;
void push(stack *,int);
int pop(stack *);
int stack_full(stack *);
int stack_empty(stack *);
int top_element(stack *);

int main()
{
	stack s;
	stack *ps;
	int ch,item,n;
	ps=&s;
	ps->top=-1;
	while(1)
	{
		printf("\n1. Push\n2. Pop\n3. Print top\n0. Exit\n\nChoice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the item to be pushed in stack:");
				scanf("%d",&item);
				push(ps,item);
				break;
			case 2: item=pop(ps);
				if(item!=-9999)
					printf("\nThe deleted item is:%d",item);
				break;
			case 3: n=top_element(ps);
				if(n!=-9999)
					printf("\nThe top element is:%d",n);
				break;
			case 0: exit(0);
			default: printf("\nWrong choice!!");
		}
	}
	return(0);
}
int stack_full(stack *ps)
{
	if(ps->top==STACKSIZE)
		return 1;
	else
		return 0;
}
int stack_empty(stack *ps)
{
	if(ps->top==-1)
		return 1;
	else
		return 0;
}
void push(stack *ps,int item)
{
	if(stack_full(ps))
	{
		printf("\nOverflow");
	}
	else
	{
		ps->top=ps->top+1;
		ps->arr[ps->top]=item;
	}
}
int pop(stack *ps)
{	
	int item;
	if(stack_empty(ps))
	{
		printf("\nUnderflow");
		return(-9999);
	}
	item=ps->arr[ps->top];
	ps->top=ps->top-1;
	return(item);
}
int top_element(stack *ps)
{
	if(stack_empty(ps))
	{
		printf("\nUnderflow");
		return(-9999);
	}
	else
	{
		return(ps->arr[ps->top]);
	}
}

