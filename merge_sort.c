#include<stdio.h>
void merge_sort(int *,int,int);
void merge(int *,int,int,int);

int main()
{
        int ar[20],n,i;
        printf("\nEnter the number of elements:");
        scanf("%d",&n);
        printf("\nEnter the elements:\n");
        for(i=0;i<n;i++)
                scanf("%d",&ar[i]);
        merge_sort(ar,0,n-1);
        printf("\nThe sorted array is:");
        for(i=0;i<n;i++)
                printf("%d ",ar[i]);
        return(0);
}
void merge_sort(int ar[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(ar,p,q);
		merge_sort(ar,q+1,r);
		merge(ar,p,q+1,r);
	}
}
void merge(int ar[],int ls,int rs,int re)
{
	int k=0,le,i,j,temp[20];
	le=rs-1;
	i=ls;
	j=rs;
	while(i<=le && j<=re)
	{
		if(ar[i]<ar[j])
		{
			k++;
			temp[k]=ar[i];
			i++;
		}
		else
		{
			k++;
			temp[k]=ar[j];
			j++;
		}
	}
	while(i<=le)
	{
		k++;
		temp[k]=ar[i];
		i++;
	}
	while(j<=re)
	{
		k++;
		temp[k]=ar[j];
		j++;
	}
	for(i=1;i<=k;i++)
		ar[ls-1+i]=temp[i];
}
