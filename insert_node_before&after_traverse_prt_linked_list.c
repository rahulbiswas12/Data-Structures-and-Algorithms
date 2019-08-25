/*
subject: C_program to create node;insert node at begin & end; traverse or print ; of a linked list
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *next;
    int info;
}node;

struct node *create(node *,int);
struct node *insert_begin(node *);
struct node *insert_end(node *);
void traverse(node *);

//the main function

void main()
{
    node *head=NULL;
    int ch,item,n;
    while(1)
    {
        printf("\nEnter choice:\n0.EXIT\n1.CREATE\n2.TRAVERSE\n3.INSERT BEGIN\n4.INSERT END\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: exit(1);
            case 1: printf("\nEnter no. of nodes:\n");
                    scanf("%d",&n);
                    head=create(head,n);
                    break;
            case 2: traverse(head);
                    break;
            case 3: head=insert_begin(head);
                    break;
            case 4: head=insert_end(head);
                    break;
            default: printf("\nWRONG CHOICE\n");
                    break;
        }
    }
}

//function to create a node

struct node *create(struct node *head,int n)
{
    int i;
    node *temp,*newnode;
    for (i=0;i<n;i++)
    {
        newnode=(node *)malloc(sizeof (node));
        printf("\nEnter the data:\n");
        scanf("%d",&newnode->info);
        newnode->next=NULL;
        if (head==NULL)
            head=newnode;
        else
            temp->next=newnode;
        temp=newnode;
    }
    return(head);
};

//function to traverse(for print)

void traverse(node *head)
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->info);
        temp=temp->next;
    }
};

//function to insert at begin of the list

struct  node *insert_begin(node *head)
{
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    printf("\nEnter the new item:\n");
    scanf("%d",&newnode->info);
    newnode->next=head;
    head=newnode;
    return(head);
};

//function to insert to the end of the list

struct node *insert_end(struct node *head)
{
    node *newnode,*temp=head;
    newnode=(node *)malloc(sizeof(node));
    printf("\nEnter the new info of new node:\n");
    scanf("%d",&newnode->info);
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    newnode->next=NULL;
    return(head);
};
