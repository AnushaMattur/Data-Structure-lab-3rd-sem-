#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int q[4];
int size=4;
int r=-1;
int f=0;
int count=0;
void insert()
{
	int elem;
	if(count==size)
	{
		printf("insertion not possible\n");
	}
	else
   {
	printf("enter the element");
	scanf("%d",&elem);
	r=(r+1)%size;
	q[r]=elem;
	++count;
   }  
}
void delet()
{
	if(count==0)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		printf("element deleted is %d",q[f]);
		f=(f+1)%size;
		--(count);
	}
}
void disp()
{
	int i,f1;
	if(count==0)
	{
		printf("display not possible\n");
	}
	else
	{
		f1=f;
		for(i=1;i<=count;++i)
		{
			printf("%d",q[f1]);
			f1=(f1+1)%size;
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
		printf("press 4 to stop\n");
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
