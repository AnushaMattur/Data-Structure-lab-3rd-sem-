#include<stdio.h>

int binary_search(int a[], int low, int high, int item)
{
	int mid;
	if(low>high)
	{
		return 0;
	}
	else
	{
			mid=(low+high)/2;
			if(item==a[mid])
			{
				return mid+1;
			}
			else
			if(item<a[mid])
			{
				return binary_search(a,low,mid-1,item);
			}
			else
			{
				return binary_search(a,mid+1,high,item);
			}
	}
}
void main()
{
	int n,i,item,pos,a[10];
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("enter the %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the item to be searched\n");
	scanf("%d",&item);
	pos= binary_search(a,0,n-1,item);
	if(pos==0)
	{
		printf("element not found\n");
	}
	else
	{
		printf("element found at pos %d",pos);
	}
}
