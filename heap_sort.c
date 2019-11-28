#include<stdio.h>
void max_heapify(int *,int,int);
void build_max_heap(int *,int);
void heapsort(int *,int);

int main()
{
	int a[30],n,i;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter the number of elements:");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	heapsort(a,n);
	printf("\nThe sorted array is:");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	return(0);
}
void max_heapify(int H[],int i,int n)
{
	int child,item,par;
	child=2*i;
	item=H[i];
	while(child<=n)
	{
		if(child<n && H[child]<H[child+1])
			child=child+1;
		if(item>=H[child])
			break;
		par=child/2;
		H[par]=H[child];
		child=2*child;
	}
	par=child/2;
	H[par]=item;
}
void build_max_heap(int A[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
		max_heapify(A,i,n);
}
void heapsort(int A[],int n)
{
	int t,i;
	build_max_heap(A,n);
	for(i=n;i>=2;i--)
	{
		t=A[1];
		A[1]=A[i];
		A[i]=t;
		max_heapify(A,1,i-1);
	}
}
