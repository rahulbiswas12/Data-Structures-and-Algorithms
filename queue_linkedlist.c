#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int info;
	struct queue *next;
};

void enqueue(struct queue **,struct queue **,int);
int dequeue(struct queue **,struct queue **);

int main()
{
	struct queue *front=NULL;
	struct queue *rear=NULL;
	int ch,item,n;
	while(1)
	{
		printf("\n1. Insert\n2. Delete\n0. Exit\n\nChoice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted in queue:");
				scanf("%d",&item);
				enqueue(&front,&rear,item);
				break;
			case 2: n=dequeue(&front,&rear);
				if(n!=-9999)
					printf("\nThe deleted item is:%d",n);
				break;
			case 0: exit(0);
			default: printf("\nWrong choice!!\n");
		}
	}
	return(0);
}
void enqueue(struct queue **pfront,struct queue **prear,int item)
{
	struct queue *newnode;
	newnode=(struct queue *)malloc(sizeof(struct queue));
	newnode->info=item;
	newnode->next=NULL;
	if(*pfront==NULL)
	{
		*pfront=newnode;
		*prear=newnode;
	}
	else
	{
		(*prear)->next=newnode;
		*prear=newnode;
	}
}
int dequeue(struct queue **pfront,struct queue **prear)
{
	struct queue *temp;
	int item;
	if(*pfront==NULL && *prear==NULL)
	{
		printf("\nUnderflow");
		return(-9999);
	}
	item=(*pfront)->info;
	temp=*pfront;
	*pfront=temp->next;
	temp->next=NULL;
	if(temp==*prear)
		*prear=NULL;
	free(temp);
	return(item);
}
