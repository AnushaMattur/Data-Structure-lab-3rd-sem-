#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *rlink;
	struct node *llink;
};
struct node *first=NULL;
void insert()
{
	int elem;
	struct node *temp,*last,*next;
	temp=malloc(sizeof(struct node));
	printf("enter the element to be inserted\n");
	scanf("%d",&elem);
	temp->data=elem;
	if ( first == NULL) 
	{
        temp->llink = NULL;
        temp->rlink = NULL;
        first=temp;
    }
    
    else if ( temp->data < first->data ) 
	{
        temp->rlink = first;
        first->llink = temp;
        temp->llink = NULL;
        first = temp;
    }

    else
	 {
        temp->rlink = first;
        int count = 0;
        
        while((temp->rlink != NULL) && ( count == 0)) 
		{
            if(temp->data < temp->rlink->data)
             {   
             	count = 1;
             	break;
             }
            else 
			{
            	temp->llink = temp->rlink;
                temp->rlink = temp->rlink->rlink;
            }
        }
 
        if(count == 1)
        {
            next = temp->rlink;
            temp->llink = next->llink;
            next->llink->rlink = temp;
            temp->rlink = next;
            next->llink = temp;
        }
      
        else
	    {
            last =temp->llink;
            last->rlink = temp;
            temp->llink=last;
        }
    }
}

void delet()
{	
	struct node *temp,*temp2,*temp3;
	int key;
	printf("enter the element to be deleted\n");
	scanf("%d",&key);
	if(first== NULL) 
	{ 
		printf("List Empty!"); 
	}	
	temp=first;
	 if(temp->data==key)
	{
		temp=first;
	 	first = temp->rlink;
	 	first->llink = NULL;
	 	printf("element deleted is %d\n", temp->data);
	 	free(temp);
	 	temp=NULL;
	}
	while(temp!=NULL)
	{	
		if(temp->data == key)
		{
			temp2 = temp->llink;
			temp3 = temp->rlink;
			temp2->rlink = temp3;
			if(temp3!=NULL) 
			{
				temp3->llink = temp2;
			}
			printf("element deleted is %d", temp->data);
	 		free(temp);
	 		temp = temp3;
		}
		if(temp!= NULL) 
		{
		 temp = temp->rlink;
		}
	}
}
void display()
{
	struct node *temp;
	
	if(first == NULL)
	{
		printf("List is empty\n");
    }
	printf("Contents of linked list:\n");

	temp = first;

	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp=temp->rlink;
	}
}
void main()
{
	int choice;

	while(1)
	{
		printf("\n");
		printf("1. Insert an element");
		printf("\n2. Delete an element");
		printf("\n3. Display\n");
		printf("4. Exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: insert();
					break;
			case 2: delet();
					break;
			case 3: display();
					break;
			default: exit(0);
		}
	}
}
