#include<stdio.h>
int partition(int *,int,int);
void quick_sort(int *,int,int);

int main()
{
	int ar[20],n,i;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	quick_sort(ar,0,n-1);
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
		printf("%d ",ar[i]);
	return(0);
}
void quick_sort(int ar[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(ar,p,r);
		quick_sort(ar,p,q-1);
		quick_sort(ar,q+1,r);
	}
}
int partition(int ar[],int p,int r)
{
	int x,i,j,q,t;
	x=ar[p];
	i=p;
	for(j=p+1;j<=r;j++)
	{
		if(ar[j]<=x)
		{
			i=i+1;
			if(i!=j)
			{
				t=ar[i];
				ar[i]=ar[j];
				ar[j]=t;
			}
		}
	}
	t=ar[p];
	ar[p]=ar[i];
	ar[i]=t;
	q=i;
	return(q);
}
		
