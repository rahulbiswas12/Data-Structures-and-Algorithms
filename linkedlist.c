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
int count(struct slist *);
void reverse(struct slist **);

int main()
{
	struct slist *head=NULL;
	int ch,item,n;
	while(1)
	{
		printf("\n1. Create\n2. Traverse\n3. Insert first\n4. Insert last\n5. Delete first\n6. Delete last\n7. Count nodes\n8. Reverse\n0. Exit\n\nChoice:");
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
			case 7: n=count(head);
				printf("\nThe number of nodes are:%d.",n);
				break;
			case 8: reverse(&head);
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
	while(loc!=NULL)
	{
		printf("%d\n",loc->info);
		loc=loc->next;
	}
}
void insert_first(struct slist **phead,int item)
{
	struct slist *newnode;
	newnode=(struct slist *)malloc(sizeof(struct slist));
	newnode->info=item;
	newnode->next=NULL;
	if(*phead!=NULL)
		newnode->next=*phead;
	*phead=newnode;
}
void insert_last(struct slist **phead,int item)
{
	struct slist *newnode;
	struct slist *loc=*phead;
	newnode=(struct slist *)malloc(sizeof(struct slist));
	newnode->info=item;
	newnode->next=NULL;
	if(loc==NULL)
	{
		*phead=newnode;
	}
	else
	{
		while(loc->next!=NULL)
		{
			loc=loc->next;
		}
		loc->next=newnode;
	}
}
void delete_first(struct slist **phead)
{
	struct slist *temp;
	if(*phead==NULL)
	{
		printf("\n The list is empty!");
	}
	else
	{
		temp = *phead;
		*phead=(*phead)->next;
		temp->next=NULL;
		printf("\n The element deleted is:%d.\n",temp->info);
		free(temp);
	}
}
void delete_last(struct slist **phead)
{
	struct slist *loc=*phead;
	struct slist *locp=NULL;
	if(*phead==NULL)
	{
		printf("\n The list is empty!");
	}
	else
	{
		while(loc->next!=NULL)
		{
			locp=loc;
			loc=loc->next;
		}
		printf("\nThe element deleted is:%d.\n",loc->info);
		if(*phead==loc)
		{
			*phead=NULL;
		}
		else
		{
			locp->next=NULL;
		}
		free(loc);
	}
}
int count(struct slist *head)
{
	int cnt;
	struct slist *loc=head;
	while(loc!=NULL)
	{
		cnt=cnt+1;
		loc=loc->next;
	}
	return(cnt);
}
void reverse(struct slist **phead)
{
	struct slist *loc=*phead;
	struct slist *locp=NULL;
	struct slist *locn;
	if(*phead==NULL || (*phead)->next==NULL)
	{
		return;
	}
	while(loc!=NULL)
	{
		locn=loc->next;
		loc->next=locp;
		locp=loc;
		loc=locn;
	}
	*phead=locp;
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
		}
		else
		{
			temp->next=newnode;
		}
		temp=newnode;
	}
}
/*void insert_any(struct slist **phead,int pos)
{
	struct slist *temp=*phead;
*/
