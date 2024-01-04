#include<stdio.h>
#include<conio.h>
#include<string.h>
char stack[50];
int top=-1;
void convert(char infix[]);
void push(char);
char pop();
main()
{
	char infix[40];
	printf("enter a string\n");
	gets(infix);
	convert(infix);
	getch();
}
void push(char symbol)
{
	if(top==49)
	printf("overflow");
	else 
	{
		top++;
		stack[top]=symbol;
	}
}
char pop()
{ char item;
   if(top==-1)
   printf("underflow");
   else
    {
    	item=stack[top];
    	top--;
    }
	return item;
}
int priority(char ch)
{
if(ch=='^')return 3;
	else if(ch=='*'||ch=='/'||ch=='%')
	return 2;
	else if(ch =='+'||ch=='-')
	return 1;
	else 
	return 0;
}
void convert(char infix[])
{
	static int index=0,pos=0;
	char postfix[40];
	int length=strlen(infix);
	//push('#');
	char temp,ch;
	while(index<length)
	{
		ch=infix[index];
		switch(ch)
		{
			case '(':
				push(ch);
				break;;
			case ')':
				temp=pop();
				while(temp!='(')
				{
					postfix[pos++]=temp;
					temp=pop();
				}
			break;
		    case '+':
		    case '-':
		    case '*':
		    case '/':
		    case '^':
		    case '%':
		    
		    while(priority(stack[top])>=priority(ch))
		    {
		    	temp=pop();
		    	postfix[pos++]=temp;
		    }
		    push(ch);
		    break;
		    default:
		    	postfix[pos++]=ch; 
				break; 
		}
		index++;
	}
	while(top>=0)
	{
	   temp=pop();
	   postfix[pos++]=temp;
	}
	postfix[pos]='\0';
	puts(postfix);	
}
