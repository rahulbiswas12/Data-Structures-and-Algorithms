#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACKSIZE 50

typedef struct stk
{
	char S[STACKSIZE];
	int top;
}stack;
void push(stack *,char);
char pop(stack *);
int stack_full(stack *);
int stack_empty(stack *);
void postfix(char *,char *);
int exppriority(char);

int main()
{
	char in[80],post[80];
	int pos=0;
	printf("\nEnter the infix expression:");
	while((in[pos++]=getchar())!='\n');
	in[--pos]='\0';
	postfix(in,post);
	printf("\nThe postfix expression is:%s",post);
	return(0);
}

void postfix(char in[],char post[])
{
	stack s;
	stack *ps;
	int p,ipos=0,ppos=0;
	char x,y;
	ps=&s;
	ps->top=-1;
	push(ps,'(');
	p=strlen(in);
	in[p]=')';
	while(!stack_empty(ps))
	{	
		x=in[ipos++];
		if(isalpha(x))
		{
			post[ppos++]=x;
		}
		else if(x=='(')
		{
			push(ps,x);
		}
		else if(x==')')
		{
			while((y=pop(ps))!='(')
			{	
				post[ppos++]=y;
			}
		}
		else
		{
			p=exppriority(x);
			while(exppriority(ps->S[ps->top])>=p)
			{
				y=pop(ps);
				post[ppos++]=y;
			}
			push(ps,x);
		}
	}
	
	post[ppos]='\0';
}
int stack_full(stack *ps)
{
	if(ps->top==STACKSIZE-1)
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
void push(stack *ps,char item)
{
	if(stack_full(ps))
	{
		printf("\nOverflow");
	}
	else
	{
		ps->top=ps->top+1;
		ps->S[ps->top]=item;
	}
}
char pop(stack *ps)
{	
	char item;
	item=ps->S[ps->top];
	ps->top=ps->top-1;
	return(item);
}
int exppriority(char c)
{
	switch(c)
	{
		case '+': 
		case '-': return(1);
		case '*': 
		case '/': return(2);
		case '^': return(3);
	}
	return(0);
}
