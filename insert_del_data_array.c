/*
subject: insert_delete_elements from an array data structure using C
*/

#include<stdio.h>

int n;
void insert(int[]);
void print(int[]);
void del(int[]);

//the main function

void main()
{
    int a[10],i,b,p;
    printf("\nEnter the no. of elements:\n");
    scanf("%d",&n);
    printf("\nEnter array elements:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    do
    {
        printf("\n1.Insert an element\n2.Print Array\n3.delete an element\n");
        scanf("%d",&b);
        if (b==1)
        {
            insert(a);
            p=1;
        }
        else if(b==2)
        {
            print(a);
            p=1;
        }
        else if (b==3)
        {
            del(a);
            p=1;
        }
        else
        {
            printf("\nERROR");
            printf("\n1.continue\n0.End\n");
            scanf("%d",&p);
        }
    }while(p==1);
}

//function to insert an element to an array

void insert(int a[])
{
    int i,l,k;
    i=n-1;
    printf("\nEnter the position to insert:\n");
    scanf("%d",&l);
    if(l<=n)
    {
        while(i>=l)
        {
            a[i+1]=a[i];
            i--;
        }
        printf("\nEnter the value to extend:\n");
        scanf("%d",&k);
        a[l]=k;
        n++;
        print(a);
    }
    else
        printf("\nARRAY HAS %d ELMENTS PRESENT so INSERTED POSSITION MUST LESS or EQUAL TO %d",n,n);
}

//function to print array

void print(int a[])
{
    int i;
    printf("\nNew array is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}

//function to delete an element from an array

void del(int a[])
{
    int l,i;
    printf("\nEnter the position to delete:\n");
    scanf("%d",&l);
    i=l;
    while(i<n)
    {
        a[i]=a[i+1];
        i=i+1;
    }
    n=n-1;
    print(a);
}
