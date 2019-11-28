#include<stdio.h>
int binary_search(int *,int,int,int);
int main()
{
	int a[20],i,n,loc,item;
	printf("\nEnter the number of elements to be inserted in array:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the item to be searched:");
	scanf("%d",&item);
	loc=binary_search(a,0,n-1,item);
	if(loc==0)
		printf("\nThe element is not present in the array.\n");
	else
		printf("\nThe element is found at index %d.\n",loc+1);
	return(0);
}
int binary_search(int a[],int lb,int ub,int item)
{
	int j=0,mid;
	while(lb<=ub && j==0)
	{
		mid=(lb+ub)/2;
		if(item==a[mid])
			j=mid;
		else if(item<a[mid])
			ub=mid-1;
		else 
			lb=mid+1;
	}
	return(j);
}	
