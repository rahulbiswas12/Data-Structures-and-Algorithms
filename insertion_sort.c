#include<stdio.h>

void input(int *,int);
void insertion_sort(int *,int);
void output(int *,int);

int main()
{
        int arr[20],n,i;
        printf("\nEnter the number of elements:");
        scanf("%d",&n);
        printf("\nEnter the elements:");
        input(arr,n);
        insertion_sort(arr,n);
        printf("\nThe sorted array is:");
        output(arr,n);
        return(0);
}
void input(int arr[],int n)
{
        int i;
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
}
void output(int arr[],int n)
{
        int i;
        for(i=0;i<n;i++)
                printf("%d ",arr[i]);
}
void insertion_sort(int arr[],int n)
{
        int i,p,t,loc=0;
	for(i=0;i<n && loc==0;i++)
	{
		p=i;
		loc=1;
		while(p>0 && arr[p-1]>arr[p])
		{
			t=arr[p];
			arr[p]=arr[p-1];
			arr[p-1]=t;
			p--;
			loc==0;
		}
	}
     
}

