#include<stdio.h>
#include<stdlib.h>

struct slist
{
	float coeff;
	int expo;
	struct slist *next;
};

void polycreate(struct slist **,int);
void polyadd(struct slist **,struct slist **,struct slist **);
struct slist *insert(struct slist *,int,int);
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
	polyadd(&head1,&head2,&head3);
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

void polyadd(struct slist **phead1,struct slist **phead2,struct slist **phead3)
{
	float sum=0;
	struct slist *loc1=*phead1,*loc2=*phead2;
	while(loc1!=NULL && loc2!=NULL)
	{
		if(loc1->expo == loc2->expo)
		{
			sum=loc1->coeff+loc2->coeff;
			if(sum!=0)
				*phead3=insert(*phead3,sum,loc1->expo);
			loc1=loc1->next;
			loc2=loc2->next;
		}
		else if(loc1->expo < loc2->expo)
		{
			*phead3=insert(*phead3,loc2->coeff,loc2->expo);
			loc2=loc2->next;
		}
		else
		{
			*phead3=insert(*phead3,loc1->coeff,loc1->expo);
			loc1=loc1->next;
		}
	}
	while(loc1!=NULL)
	{
		*phead3=insert(*phead3,loc1->coeff,loc1->expo);
		loc1=loc1->next;
	}
	while(loc2!=NULL)
	{
		*phead3=insert(*phead3,loc2->coeff,loc2->expo);
		loc2=loc2->next;
	}
}

struct slist *insert(struct slist *head,int c,int e)
{
	struct slist *newnode,*loc;
	newnode=(struct slist *)malloc(sizeof(struct slist));
	newnode->coeff=c;
	newnode->expo=e;
	newnode->next=NULL;
	loc=head;
	if(loc==NULL)
		head=newnode;
	else
	{
		while(loc->next!=NULL)
			loc=loc->next;
		loc->next=newnode;
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

