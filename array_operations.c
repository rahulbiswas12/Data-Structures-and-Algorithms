#include<stdio.h>
#include<stdlib.h>
void initialize_array(int [],int);
void insert(int [],int *,int,int);
void traverse(int [],int);
void delete(int [],int *,int,int *);
void reverse(int [],int);
int main()
{
	int ch,n,a[50],k,item;
	while(1)
	{
		printf("\n1. Initialize array\n2. Traverse\n3. Insert\n4. Delete\n5. Reverse\n0. Exit\n\nChoice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter no.of elements : ");
				scanf("%d",&n);
				initialize_array(a,n);
				break;
			case 2: traverse(a,n);
				break;
			case 3: printf("\nEnter the location for insertion : ");
				scanf("%d",&k);
				printf("\nEnter the value to be inserted : ");
				scanf("%d",&item);
				insert(a,&n,k-1,item);
				break;
			case 4: printf("\nEnter location for deletion : ");
				scanf("%d",&k);
				delete(a,&n,k-1,&item);
				printf("\nDeleted item is %d",item);
				break;
			case 5: reverse(a,n);
				break;
			case 0: exit(0);
			default: printf("\nWrong Choice ......");
		}	
	}
	return(0);
}
void initialize_array(int a[],int n)
{
	int i;
	printf("\nEnter %d values\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}	
void traverse(int a[],int n)
{
	int i;
	printf("The values are:\n");
	for(i=0;i<n;i++)
		printf("\nLocation = %d, Value = %d",i+1,a[i]);
}
void insert(int a[],int *pn,int k,int item)
{
	int j;
	for(j=*pn-1;j>=k;j--)
	{	
		a[j+1]=a[j];
	}
	a[k]=item;
	*pn=*pn+1;
}
void delete(int a[],int *pn,int k,int *pitem)
{
	int j;
	*pitem=a[k];
	for(j=k;j<*pn-1;j++)
	{
		a[j]=a[j+1];
	}
	*pn=*pn-1;
}
void reverse(int a[],int n)
{
	int k,j,t;
	k=n/2;
	for(j=0;j<k;j++)
	{
		t=a[j];
		a[j]=a[n-1-j];
		a[n-1-j]=t;
	}
}
