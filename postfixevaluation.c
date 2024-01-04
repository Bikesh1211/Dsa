#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
float stack[10];
int top=-1;
void push(char);
float pop();
float eval(char [],float []);
main()
{
	int i=0;
	char suffix[20];
	float value[20],result;
	printf("enter a valid postfix expression \n");
	gets(suffix);
	//scanf("%s",suffix);
	while(suffix[i]!='\0')
	{
		if(isalpha(suffix[i]))
		{
			fflush(stdin);
		printf("\n enter the value of %c",suffix[i]);
		scanf("%f",&value[i]);
		}	
		i++;
	}
	result=eval(suffix, value);
	printf("The result of %s %f",suffix,result);
	getch();
}
float eval(char suffix[],float data[])
{
	int i=0;
	float op1,op2,res;
	char ch;
	while(suffix[i]!='\0')
	{
		ch=suffix[i];
		if(isalpha(suffix[i]))
		{
			push(data[i]);
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '+': push(op1+op2);
							break;
				case '-': push(op1-op2);
							break;
				case '*': push(op1*op2);
							break;
				case '/': push(op1/op2);
							break;
				case '^': push(pow(op1,op2));
							break;									
			}
		}
		i++;
	}
	res=pop();
	return (res);
}
void push(char num)
{
	top++;
	stack[top]=num;
}
float pop()
{
	float num;
	num=stack[top];
	top--;
	return(num);
}