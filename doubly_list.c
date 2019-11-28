#include<stdio.h>
#include<stdlib.h>
struct slist
{
	struct slist *prev;
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
	struct slist *loc=head,*current;
	printf("\nFrom left to right:\n");
	while(loc!=NULL)
	{
		printf("%d\n",loc->info);
		current=loc;
		loc=loc->next;
	}
	printf("\nFrom right to left:\n");
	loc=current;
	while(loc!=NULL)
	{
		printf("%d\n",loc->info);
		loc=loc->prev;
	}
}
void insert_first(struct slist **phead,int item)
{
	struct slist *newnode;
	newnode=(struct slist *)malloc(sizeof(struct slist));
	newnode->info=item;
	newnode->prev=NULL;
	newnode->next=*phead;
	(*phead)->prev=newnode;
	*phead=newnode;
}
void insert_last(struct slist **phead,int item)
{
	struct slist *newnode;
	struct slist *loc=*phead;
	while(loc->next!=NULL)
	{
		loc=loc->next;
	}
	newnode=(struct slist *)malloc(sizeof(struct slist));
	newnode->info=item;
	newnode->next=NULL;
	newnode->prev=loc;
	loc->next=newnode;
}
void delete_first(struct slist **phead)
{
	struct slist *temp=*phead;
	*phead=temp->next;
	if(*phead!=NULL)
	{
		(*phead)->prev=NULL;
		temp->next=NULL;
	}
	printf("%d is deleted.\n",temp->info);
	
	free(temp);
}
void delete_last(struct slist **phead)
{
	struct slist *loc=*phead,*temp;
	while(loc->next!=NULL)
	{
		loc=loc->next;
	}
	temp=loc->prev;
	temp->next=NULL;
	loc->prev=NULL;
	printf("%d is deleted.\n",loc->info);
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
		newnode->next=NULL;
		if(*phead==NULL)
		{
			*phead=newnode;
			newnode->prev=NULL;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
		}
		temp=newnode;
	}
}

