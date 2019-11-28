#include<stdio.h>
#include<stdlib.h>
struct slist
{
	int info;
	struct slist *next;
};
void traverse(struct slist *);
void insert_first(struct slist **,int);
void insert_last(struct slist **,int);
void create(struct slist **,int);
void delete_first(struct slist **);
void delete_last(struct slist **);

int main()
{
	struct slist *head=NULL;
	int ch,item,n;
	while(1)
	{
		printf("\n1. Create\n2. Traverse\n3. Insert first\n4. Insert last\n5. Delete first\n6. Delete last\n0. Exit\n\nChoice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the number of elements for the list:");
				scanf("%d",&n);
				create(&head,n);
				break;
			case 2: traverse(head);
				break;
			case 3: printf("\n Enter the item to be inserted at first:");
				scanf("%d",&item);
				insert_first(&head,item);
				break;
			case 4: printf("\n Enter the item to be inserted at last:");
				scanf("%d",&item);
				insert_last(&head,item);
				break;
			case 5: delete_first(&head);
				break;
			case 6: delete_last(&head);
				break;
			case 0: exit(0);
			default: printf("\nWrong choice!!!!\n");
		}
	}
	return(0);
}
void traverse(struct slist *head)
{
	struct slist *loc=head;
	if(head==NULL)
	{
		printf("Empty list.");
	}
	
	do{
		printf("%d\n",loc->info);
		loc=loc->next;
	  }while(loc!=head);
}
void insert_first(struct slist **phead,int item)
{
	struct slist *newnode,*loc=*phead;
	while(loc->next!=*phead)
	{
		loc=loc->next;
	}
	newnode=(struct slist *)malloc(sizeof(struct slist));
	newnode->info=item;
	newnode->next=*phead;
	loc->next=newnode;
	*phead=newnode;
}
void insert_last(struct slist **phead,int item)
{
	struct slist *newnode;
	struct slist *loc=*phead;
	while(loc->next!=*phead)
	{
		loc=loc->next;
	}
	newnode=(struct slist *)malloc(sizeof(struct slist));
	newnode->info=item;
	newnode->next=*phead;
	loc->next=newnode;
}
void delete_first(struct slist **phead)
{
	struct slist *temp,*loc=*phead;
	printf("%d is deleted.\n",(*phead)->info);
	while(loc->next!=*phead)
	{
		loc=loc->next;
	}
	temp=*phead;
	if(loc==*phead)
		*phead=NULL;
	else
	{
		*phead=temp->next;
		loc->next=*phead;
	}
	temp->next=NULL;
	free(temp);
}
void delete_last(struct slist **phead)
{
	struct slist *loc=*phead;
	struct slist *locp;
	while(loc->next!=*phead)
	{
		locp=loc;
		loc=loc->next;
	}
	printf("%d is deleted.\n",loc->info);
	if(loc==*phead)
		*phead=NULL;
	else
		locp->next=*phead;
	loc->next=NULL;
	free(loc);
}

void create(struct slist **phead,int n)
{
	int i;
	int item;
	struct slist *newnode;
	struct slist *temp;
	if(*phead!=NULL)
	{
		printf("\n List exists!");
	}
	for(i=0;i<n;i++)
	{
		newnode=(struct slist *)malloc(sizeof(struct slist));
		printf("\n Enter item:");
		scanf("%d",&item);
		newnode->info=item;
		if(*phead==NULL)
		{
			*phead=newnode;
		}
		else
		{
			temp->next=newnode;
		}
		temp=newnode;
	}
	newnode->next=*phead;
}

