#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
char s[10];
int top=-1;
char infix[10];
char postfix[10];
void inf_to_post();
int ir(char);
int sr(char);
void push(char);
char pop();
void main()
{
	printf("enter an infix expression\n");
	scanf("%s",&infix);
	inf_to_post();
	printf("the postfix expression is %s", postfix);
}
void inf_to_post()
{
	int i;
	int j=0;
	char symbol;
	push('#');
	for(i=0;i<=strlen(infix)-1;++i)
	{
		symbol=infix[i];
		while(sr(s[top])>ir(symbol))
		{
			postfix[j]=pop();
			++j;
		}
		if(sr(s[top])<ir(symbol))
		{
			push(symbol);
		}
		if(sr(s[top])==ir(symbol))
		{
			pop();
		}
	}
	while(s[top]!='#')
	{
		postfix[j]=pop();
		++j;
	}
	postfix[j]='\0';
}
int ir(char symbol)
{
	switch(symbol)
	{
		case'+':
		case'-': return 1;
		case'*':
		case'/': return 3;
		case'$':
		case'^': return 6;
		case'(': return 9;
		case')': return 0;
		default: return 7;
	}
}
int sr(char symbol)
{
	switch(symbol)
	{
		case'+':
		case'-': return 2;
		case'*':
		case'/': return 4;
		case'$':
		case'^': return 5;
		case'(': return 0;
		case'#': return -1;
		default: return 8;
	}
}
void push(char symbol)
{
	s[++top]=symbol;
}
char pop()
{
	return s[top--];
}
