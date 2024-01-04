#include<conio.h>
#include<stdio.h>
#define max 3
void push();
void pop();
void display();
int menu();
int stack[max], top=-1;
  main()
{
    int ch;
    //clrscr();
    do{
        ch=menu();
        switch(ch)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
            case 4: 
			exit(0);
            default: printf("\nEnter a valid choice!!");
        }
    }while(1);
    getch();
}
 
int menu()
{
    int ch;
    printf("\nStack");
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
    printf("\nEnter your Choice:");
    scanf(" %d",&ch);
    return ch;
}
 
void push()
{
    if(top==max-1)
        printf("\nOverflow");
    else
    {
        int element;
        printf("\nEnter Element:");
        scanf("%d",&element);
        top++;
        printf("\nElement(%d) has been pushed at %d", element, top);
        stack[top]=element;
    }
}
 
void pop()
{
    if(top==-1)
        printf("\nUnderflow");
    else
    {
        
        printf("\nELement has been popped out%d",stack[top]);
        top--;
    }
}
 
void display()
{
    if(top==-1)
        printf("\nStack is Empty!!");
    else
    {
        int i;
        for(i=top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
}
