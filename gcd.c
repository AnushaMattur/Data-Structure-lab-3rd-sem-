#include<stdio.h>
void main()
{
	int m,n;
	printf("enter m and n\n");
	scanf("%d%d",&m,&n);
	printf("gcd=%d",gcd(m,n));
}
int gcd(int m,int n)
{
	if(n==0)return m;
	else
	if(n>m)return gcd(n,m);
	else
	return gcd(n,m%n);
}
