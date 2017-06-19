#include<stdio.h>
#include<process.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
char postfix[10];
int s[10];
int top=-1;
int opnd1,opnd2,res;
char symbol;
void evalpost();
void push(int);
int pop();
int compute(int,char,int);
void main()
{
	printf("enter the postfix expression\n");
	scanf("%s",&postfix);
	evalpost();
	printf("%d",res);	
}
void evalpost()
{
	int j;
	for(j=0;j<=strlen(postfix)-1;++j)
	{
		symbol=postfix[j];
		if(isdigit(symbol))
		{
			push(symbol-'0');
		}
		else
		{
			opnd2=pop();
			opnd1=pop();
			res=compute(opnd1,symbol,opnd2);
			push(res);
		}
	}
	res=pop();
}
void push(int item)
{
	s[++top]=item;
}
int pop()
{
	return s[top--];
}
compute(int opnd1,char symbol,int opnd2)
{
	switch(symbol)
	{
		case '+': return opnd1+opnd2;
		case '-': return opnd1-opnd2;
		case '*': return opnd1*opnd2;
		case '/': return opnd1/opnd2;
		case '$':
		case '^': return pow(opnd1,opnd2);
	}
}
