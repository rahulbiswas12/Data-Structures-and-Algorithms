#include<stdio.h>
#include<stdlib.h>

struct slist
{
	float coeff;
	int expo;
	struct slist *next;
};

void polycreate(struct slist **,int);
void polymult(struct slist **,struct slist **,struct slist **);
struct slist *insert(struct slist *,float,int);
void traverse(struct slist *);

int main()
{
	struct slist *head1=NULL,*head2=NULL,*head3=NULL;
	int n,ch;
	system("clear");
	printf("\nEnter the number of terms for 1st expression:");
	scanf("%d",&n);
	printf("\nCreation of polynomial 1:\n");
	polycreate(&head1,n);
	printf("\nEnter the number of terms for 2nd expression:");
	scanf("%d",&n);
	polycreate(&head2,n);
	polymult(&head1,&head2,&head3);
	printf("\nPolynomial 1:");
	traverse(head1);
	printf("\nPolynomial 2:");
	traverse(head2);
	printf("\nResultant Polynomial:");
	traverse(head3);
}

void polycreate(struct slist **phead,int n)
{
	int i,e;
	float c;
	struct slist *newnode,*temp;
	for(i=0;i<n;i++)
	{
		printf("\nEnter coefficient:");
		scanf("%f",&c);
		printf("\nEnter exponent:");
		scanf("%d",&e);
		newnode=(struct slist *)malloc(sizeof(struct slist));
		newnode->coeff=c;
		newnode->expo=e;
		newnode->next=NULL;
		if(*phead==NULL)
			*phead=newnode;
		else
			temp->next=newnode;
		temp=newnode;
	}
}

void polymult(struct slist **phead1,struct slist **phead2,struct slist **phead3)
{
	struct slist *loc1,*loc2;
	int e;
	float c;
	if(*phead1==NULL || *phead2==NULL)
	{
		printf("\nMultiplication not possible!\n");
		return;
	}
	loc1=*phead1;
	while(loc1!=NULL)
	{
		loc2=*phead2;
		while(loc2!=NULL)
		{
			c=loc1->coeff*loc2->coeff;
			e=loc1->expo+loc2->expo;
			*phead3=insert(*phead3,c,e);
			loc2=loc2->next;
		}
		loc1=loc1->next;
	}
}
	


struct slist *insert(struct slist *head,float c,int e)
{
	struct slist *newnode,*loc=head,*locp=NULL;
	while(loc!=NULL && loc->expo<e)
	{
		locp=loc;
		loc=loc->next;
	}
	if(loc!=NULL && loc->expo==e)
	{
		loc->coeff=loc->coeff+c;
		return(head);
	}
	newnode=(struct slist *)malloc(sizeof(struct slist));
	newnode->coeff=c;
	newnode->expo=e;
	if(head==loc)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		newnode->next=locp->next;
		locp->next=newnode;
	}
	return(head);
	
}
void traverse(struct slist *head)
{
        struct slist *loc=head;
        while(loc!=NULL)
        {
                printf("%gX^%d + ",loc->coeff,loc->expo);
                loc=loc->next;
        }
}

