#include<stdio.h>

void input(int *,int);
void bubblesort(int *,int);
void output(int *,int);

int main()
{
	int arr[20],n,i;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	input(arr,n);
	bubblesort(arr,n);
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
		printf("%d\n",arr[i]);
}
void bubblesort(int arr[],int n)
{
	int i,j,t,loc=0;
	for(i=0;i<n && loc==0;i++)
	{
		loc=1;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j+1]<arr[j])
			{
				t=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=t;
				loc=0;
			}
		}
	}
}	
