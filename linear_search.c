#include<stdio.h>
int linear_search(int *,int,int);
int main()
{
	int a[20],i,n,item,loc;
	printf("\nEnter the number of elements to be inserted in array:");
	scanf("%d",&n);
	printf("\nEnter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to be searched:");
	scanf("%d",&item);
	loc=linear_search(a,n-1,item);
	if(loc==-1)
		printf("\nThe item is not present in the array.\n");
	else
		printf("\nThe item is found at index %d.\n",loc);
	return(0);
}
int linear_search(int a[],int n,int item)
{
	int i=1,loc=-1;
	while(i<=n)
	{
		if(item==a[i])
		{
			loc=i;
			break;
		}
		i=i+1;
		
	}
	return(loc);
}
