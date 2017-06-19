#include<stdio.h>
int count=0;
void main()
{
	int n;
	printf("enter the number of discs to be moved\n");
	scanf("%d",&n);
	tower (n,'A','B','C');
	printf("number of moves=%d",count);
}
tower(int n, int source, int temp, int destination)
{
	if(n==1)
	{
		printf("move disc 1 from %c to %c", source, destination);
		count++;
		return;
	}
	tower(n-1,source,destination,temp);
	printf("move disc %d from %c to %c\n",n,source,destination);
	count++;
	tower(n-1,temp,source,destination);
}
