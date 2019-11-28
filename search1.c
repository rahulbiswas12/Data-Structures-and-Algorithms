#include<stdio.h>
main()
{

	int a[100],n,i,s,j,f;
	printf("enter the no of elements");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);

	}
	printf("array");
	for(i=0;i<n;i++)
	{	printf("%d",a[i]);
	}
	printf("enter the element to search");
	scanf("%d",&s);
	for(i=0;i<n;i++)
	{
		if(a[i]==s)
			{
				j=i+1;
				f=1;
			}
	}
	
	if(f==1)
		printf("the element is in the %d th position",j);
	else
		printf("not found");
}
