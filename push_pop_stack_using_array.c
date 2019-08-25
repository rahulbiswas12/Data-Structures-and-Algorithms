/*
subject: insertion & deletion of a stack of STACKMAX OF 05 ELEMENTS using array
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int push(int ,int );
int pop(int );
void display(int );
int arr[MAX];

//the main function

void main()
{
    int top=-1,ch,item;
    while(1)
    {
        printf("\nEnter Your choice:\n0.Exit\n1.PUSH ELEMENT IN THE STACK\n2.POP ELEMENT FROM THE STACK\n3.DISPLAY STACK\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: exit(0);
            case 1: top=push(top,item);
                    break;
            case 2: top=pop(top);
                    break;
            case 3: display(top);
                    break;
            default: printf("\nWRONG CHOICE\n");
        }
    }
}

//function to push an element in the stack

int push(int top,int item)
{
    if (top==MAX-1)
    {
        printf("\nSTACK IS OVERFLOW\n");
    }
    else
    {
        printf("\nEnter the new item to be pushed:\t");
        scanf("%d",&item);
        top++;
        arr[top]=item;
    }
    return(top);
}

//function to pop an element from the stack

int pop(int top)
{
    int item;
    if (top==-1)
        printf("\nSTACK IS UNDERFLOW\n");
    else
    {
        item=arr[top];
        printf("\npopped element is: %d\n",item);
        top--;
    }
    return(top);
}

//function to display the stack

void display(int top)
{
    int i=top;
    printf("\nSTACK IS:\n");
    if(i==-1)
    {
        printf("\nNULL\n");
    }
    else
    {
        for(i=top;i>=0;i--)
            printf("\n%d",arr[i]);
    }

}
