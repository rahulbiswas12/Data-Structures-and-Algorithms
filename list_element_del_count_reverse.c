/*
Subject: C_program to create,insert,delete 1st & Last element,count nodes,reverse order of linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct node *create(struct node *,int );
struct node *insert(struct node *);
struct node *del_1st(struct node *head);
void printList(struct node* n);
struct node *del_last(struct node *head);
struct node *count(struct node *haed);
struct node *rev(struct node *head);

typedef struct node
{
    int info;
    struct node *next;
}node;

//the main function

void main()
{
    struct node *head=NULL;
    int ch,n;
    while(1)
    {
        printf("\nEnter your choice:\n0.EXIT\n1.CREATE LINKED LIST.\n2.INSERT NEW ELEMENT.\n3.DELETE 1ST ELEMENT.\n4.DELETE LAST ELEMENT.\n5.COUNT ELEMENTS.\n6.PRINT LIST.\n7.PRINT REVERSE ORDER LIST.\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 0: exit(0);
            case 1: if (head!=NULL)
                    {
                        printf("\nAlready Created.\nFIRST DELETE PREVIOUS CREATION TO CREATE ANOTHER.\n");
                    }
                    else
                    {
                        printf("\nEnter no. of nodes:\n");
                        scanf("%d",&n);
                        head=create(head,n);
                    }
                    break;
            case 2: head=insert(head);
                    break;
            case 3: head=del_1st(head);
                    break;
            case 4: head=del_last(head);
                    break;
            case 5: head=count(head);
                    break;
            case 6: printList(head);
                    break;
            case 7: head=rev(head);
                    break;
            default: printf("\nWRONG CHOICE\n");
        }
    }
}

//function to create a node in a list

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
}

//this function insert a new node to the list

struct node *insert(struct node *head)
{
    struct node *nnode,*temp=head;
    nnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
        printf("\nMust create a list First\n");
    else
    {
        printf("\nInsert info to new node:\n");
        scanf("%d",&nnode->info);
        nnode->next=NULL;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=nnode;
        return(head);
    }
}
//This function is to delete 1st element in the list
struct node *del_1st(struct node *head)
{
        if (head==NULL)
        {
            printf("\nEMPTY LIST\n");
            return(head);
        }
        else
        {
            struct node *temp=head;
            head=head->next;
            printf("\ndeleted item is: %d\n",temp->info);
            temp->next=NULL;
            free(temp);
            return(head);
        }
}
//This function is to delete Last element in the list
struct node *del_last(struct node *head)
{
    if (head==NULL)
    {
        printf("\nEMPTY LIST\n");
        return(head);
    }
    else
    {
        struct node *temp,*ptr;
        temp=head;
        while(temp->next!=NULL)
        {
            ptr=temp;
            temp=temp->next;
        }
        printf("\nDeleted item is: %d",temp->info);
        ptr->next=NULL;
        free(temp);
        return(head);
    }
};
//This function is to count node in the linked list
struct node *count(struct node *head)
{
    struct node *temp;
    int count=0;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("\nNumber of nodes: %d",count);
    return(head);
};
// This function prints contents of linked list starting from
// the given node
void printList(struct node* n)
{
    if (n==NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        printf("\nLINKED IS: \n");
        while (n != NULL)
        {
            printf("%d->",n->info);
            n = n->next;
        }
    }
}

//this function prints contents of linked list in reverse order

struct node *rev(struct node *head)
{
    if (head==NULL)
    {
        printf("\nLIST IS EMPTY\n");
        return(head);
    }
    struct node *loc,*locp,*locn;
    loc=head;
    locp=NULL;
    while(loc!=NULL)
    {
        locn=loc->next;
        loc->next=locp;
        locp=loc;
        loc=locn;
    }
    head=locp;
    printList(head);
    return(head);
};
