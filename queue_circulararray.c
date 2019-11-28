#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 5

struct queue
{
	int arr[QUEUESIZE];
	int front;
	int rear;
};
int queue_empty(struct queue *);
int queue_full(struct queue *);
void enqueue(struct queue *,int);
int dequeue(struct queue *);

int main()
{
	struct queue q;
	struct queue *pq;
	int ch,item;
	pq=&q;
	pq->front = -1;
	pq->rear = -1;
	while(1)
	{
		printf("\n1. Insert\n2. Delete\n0. Exit\n\nChoice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				enqueue(pq,item);
				break;
			case 2: item=dequeue(pq);
				if(item!=-9999)
					printf("\nThe deleted item is:%d",item);
				break;
			case 0: exit(0);
			default: printf("\nWrong choice!!");
		}
	}
	return(0);
}
int queue_full(struct queue *pq)
{
	if(pq->rear==QUEUESIZE-1 && pq->front==0|| pq->front== pq->rear+1)
		return(1);
	else
		return(0);
}
int queue_empty(struct queue *pq)
{
	if(pq->front==-1 && pq->rear==-1)
		return(1);
	else
		return(0);
}
void enqueue(struct queue *pq,int item)
{
	if(queue_full(pq))
	{
		printf("\nQueue is full.");
		return;
	}
	if(queue_empty(pq))
	{
		pq->front=0;
		pq->rear=0;
	}
	else if(pq->rear== QUEUESIZE-1)
		pq->rear=0;
	else 
		pq->rear=pq->rear+1;
	pq->arr[pq->rear]=item;
}
int dequeue(struct queue *pq)
{
	int item;
	if(queue_empty(pq))
	{
		printf("\nUnderflow");
		return(-9999);
	}
	item=pq->arr[pq->front];
	if(pq->front==pq->rear)
		pq->front=pq->rear=-1;
	else if(pq->front==QUEUESIZE-1)
		pq->front=0;
	else
		pq->front+=1;
	return(item);
}
