#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
struct node
{
	struct node *llink;
	struct node *rlink;
	int data;
};
struct node *first=NULL;
void ins_front()
{
	struct node *p;
	int elem;
	p=malloc(sizeof(struct node));
	printf("enter the element to be inserted");
	scanf("%d",&elem);
	p->llink=NULL;
	p->data=elem;
	p->rlink=NULL;
	if(first==NULL)
	{
		first=p;
	}
	else
	{
		p->rlink=first;
		first->llink=p;
		first=p;
	}
}
void ins_rear()
{
	int elem;
	struct node *p;
	struct node *temp;
	p=malloc(sizeof(struct node));
	printf("enter the element to be inserted");
	scanf("%d",&elem);
	p->data=elem;
	p->llink=NULL;
	p->rlink=NULL;
	if(first==NULL)
	{
		first=p;
	}
	else
	{
		temp=first;
		while(temp->rlink!=NULL)
		{
			temp=temp->rlink;
		}
		temp->rlink=p;
		p->llink=temp;
	}
}
void del_front()
{
	struct node *temp;
	if(first==NULL)
	{
		printf("del not possible");
	}
	else if(first->rlink==NULL)
	{
		printf("elem del is %d",first->data);
		free(first);
		first=NULL;
	}
	else
	{
		temp=first;
		first=first->rlink;
		printf("elem del is %d",temp->data);
		free(temp);
		temp=NULL;
		first->llink=NULL;
	}
}
void del_rear()
{
	struct node *temp,*x;
	if(first==NULL)
	{
		printf("del not pos\n");
	}
	else if(first->rlink==NULL)
	{
		printf("element deleted is %d",first->data);
		free(first);
		first=NULL;
	}
	else
	{
		temp=first;
		while(temp->rlink->rlink!=NULL)
		{
			temp=temp->rlink;
		}
		printf("element del is %d",temp->rlink->data);
		x=temp->rlink;
		free(x);
		temp->rlink=NULL;
	}
}
void display()
{
	struct node *temp;
	if(first==NULL)
	{
		printf("display not possible");
	}
	else if(first->rlink==NULL)
	{
		printf("element is %d",first->data);
	}
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->rlink;
		}
	}
}
void ins_pos()
{
	int elem,pos;
	struct node *p,*temp,*x;
	p=malloc(sizeof(struct node));
	printf("enter the element to be inserted\n");
	scanf("%d", & elem);
	p->data=elem;
	p->llink=NULL;
	p->rlink=NULL;
	printf("enter the position at which element has to be inserted");
	scanf("%d", & pos);
	if(first==NULL && pos==1)
	{
		first=p;
	}
	else if(first==NULL)
	{
		free(p);
		p=NULL;
		printf("ainvalid position\n");
	}
	else if(pos==1)
	{
		p->rlink=first;
		first->llink=p;
		first=p;
	}
	else
	{
	int count=1;
	temp=first;
	while(temp->rlink!=NULL && count!=pos)
	{
		temp=temp->rlink;
		count++;
	}
	if(count==pos)
	{
		x=temp->llink;
		p->rlink=temp;
		temp->llink=p;
		p->llink=x;
		x->rlink=p;
	}
	else
	{
	printf("invalid position\n");
	free(p);
	p=NULL;
   }
   }
}
void del_pos()
{
	int pos,count;
	struct node *temp,*x,*y;
	printf("enter the position\n");
	scanf("%d",&pos);
	if(first==NULL)
	{
		printf("deletion not possible\n");
	}
	else if(pos==1)
	{
		temp=first;
		first=first->rlink;
		printf("element deleted is %d",temp->data);
		free(temp);
		temp=NULL;
		first->llink=NULL;
	}
	else
	{
		temp=first;
		count=1;
		while(temp->rlink!=NULL && count!=pos)
		{
			temp=temp->rlink;
			count++;
		}
		if(temp==NULL)
		{
			printf("invalid position\n");
		}
		else
		{
			printf("element deleted is %d",temp->data);
			x=temp->llink;
			y=temp->rlink;
			free(temp);
			temp=NULL;
			x->rlink=y;
			y->llink=x;
		}
	}
}
void main()
{
	int choice;
	while(1)
	{
		printf("enter 1 to insert front\n 2 to insert rear\n 3 to delete front\n 4 to delete rear\n 5 to display\n 6 to insert at a position\n 7 to delete at a position\n 8 to exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: ins_front();
					break;
			case 2: ins_rear();
					break;
			case 3: del_front();
					break;
			case 4: del_rear();
					break;
			case 5: display();
					break;
			case 6: ins_pos();
					break;
			case 7: del_pos();
					break;
			default: exit(0);
					 break;
		}
    }
}
