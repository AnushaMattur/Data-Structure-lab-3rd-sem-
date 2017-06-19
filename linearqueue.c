#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int q[4];
int size=4;
int r=-1;
int f=0;
void insert()
{
	int elem;
	if(r==size-1)
	{
		printf("insertion not possible\n");
	}
	else
	{
		printf("enter the elem");
		scanf("%d",&elem);
		++r;
		q[r]=elem;
	}
}
void delet()
{
	if(f>r)
	{
		printf("queue is empty,so deletin not possible");
	}
	else
	{
		printf("element deleted is %d",q[f]);
		++f;
	}
}
void disp()
{
	int i;
	if(f>r)
	{
		printf("queue is empty, so display not possible");
	}
	else
	{
		for(i=f;i<=r;i++)
	{
		printf("%d\t",q[i]);
	}
    }
 }
 void main()
{
	int choice;
	while(1)
	{
		printf("press 1 to insert\n");
		printf("press 2 to delet\n");
		printf("press 3 to disp\n");
		printf("press 4 to exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert();
			        break;
		    case 2: delet();
		            break;
		    case 3: disp();
		            break;
		    default: exit(0);
		             break;
		}
	}
}
