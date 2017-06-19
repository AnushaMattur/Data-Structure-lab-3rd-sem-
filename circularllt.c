#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
struct node *first=NULL;
void ins_front()
{
		int elem;
		struct node *p;
		p=malloc(sizeof(struct node));
		printf("enter the element to be inserted\n");
		scanf("%d", & elem);
		p->data=elem;
		p->link=NULL; 
		if(first==NULL)
		{
			first=p;
			first->link=first;
		}
		else
		{
			p->link=first->link;
			first->link=p;
		}
}
void ins_rear()
{
		int elem;
		struct node *p, *temp;
		p=malloc(sizeof(struct node));
		printf("enter the element to be inserted\n");
		scanf("%d",&elem);
		p->data=elem;
		p->link=NULL;
		if(first==NULL)
		{
			first=p;
		    first->link=first;
		}
		else
		{
			p->link=first->link;
			first->link=p;
			first=p;
		}
}
void del_front()
{
		struct node *temp;
		if(first==NULL)
		{
			printf("deletion not possible\n");
		}
		else if(first->link==first)
		{
			printf("element deleted is %d",first->data);
			free(first);
			first=NULL;
		}
		else
		{
			temp=first->link;
			first->link=temp->link;
			temp->link=NULL;
			printf("element deleted is %d",temp->data);
			free(temp);
			temp=NULL;
		}
}
void del_rear()
{
	struct node *prev,*cur;
	if(first==NULL)
	{
		printf("deletion not possible\n");
	}
	else if(first->link==first)
	{
		printf("element deleted is %d",first->data);
		free(first);
		first=NULL;
	}
	else
	{
		prev=first;
		cur=first->link;
		while(cur!=first)
		{
			prev=cur;
			cur=cur->link;
		}
		prev->link=cur->link;
		cur->link=NULL;
		printf("elem del is %d",cur->data);
		free(cur);
		first=prev;
    }
}
void display()
{
	struct node *temp;
	if(first==NULL)
	{
		printf("list empty so display not possible\n");
    }
	else if(first->link==first)
    {
    	printf("%d\n",first->data);
    	
	}
	else
	{
		
	temp=first;
	while(temp->link!=first)
	{
		temp=temp->link;
		printf("%d\t",temp->data);
	}
	temp=temp->link;
	printf("%d",temp->data);
}
}
void ins_pos()
{
	int count=1;
	int elem,pos;
	struct node *p,*prev,*cur;
	p=malloc(sizeof(struct node));
	printf("enter the element to be inserted\n");
	scanf("%d",&elem);
	p->data=elem;
	p->link=NULL;
	printf("enter the position at which element has to be inserted\n");
	scanf("%d",&pos);
	if(first==NULL && pos==1)
	{
		first=p;
		first->link=first;
	}
	else if(first==NULL)  //if first is null & position is something other than 1
	{
		free(p);
		p=NULL;
		printf("ainvalid position");
	}
	else if(pos==1)
	{
		p->link=first->link;
		first->link=p;
	}
	else
	{
		int count=1;
		prev=NULL;
		cur=first->link;
		while(pos!=count && prev!=first)
		{
			prev=cur;
			cur=cur->link;
			count++;
		}
		if(count==pos)
		{
			prev->link=p;
			p->link=cur;
			if(prev==first)
			{
				first=p;
			}
		}
		else
		{
			printf("invalid position\n");
	    }   
	}
}
void del_pos()
{
	struct node *cur,*prev;
	int count,pos;
	printf("enter the position\n");
	scanf("%d",&pos);
	if(first==NULL)
	{
		printf("list empty\n");
	}
	 else if(pos==1 && first->link==first)
	 {
		printf("element deleted is %d",first->data);
		free(first);
		first=NULL; 	
	 }
	else if( pos==1)
	{
		cur=first->link;
		first->link=cur->link;
		printf("element deleted is %d",cur->data);
		free(cur);
		cur=NULL;
	}
	else
	{
		prev=NULL;
		cur=first->link;
		count=1;
		while(prev!=first && count!=pos)
		{
			prev=cur;
			cur=cur->link;
			count++;
		}
		if(prev==first && count!=pos)
		{
			printf("invalid position\n");
		}
		else if(count==pos) 
		{
			printf("element deleted is %d",cur->data);
			prev->link=cur->link;
			if(cur==first)
			{
				first=prev;
				free(cur);
				cur=NULL;
			}
			free(cur);
			cur=NULL;
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

