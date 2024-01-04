//Program for Circular Queue implementation through Array
#include <stdio.h>
#include<conio.h>
#include<process.h>
#define MAXSIZE 3
int cq[MAXSIZE]={0};
int front=-1,rear=-1;
void main()
{
 void add(int);
 void del();
 void display();
 int ch,i,num;
 //front = -1;
 //rear = -1;
 //clrscr();
 printf("\nProgram for Circular Queue demonstration through array");
 while(1)
 {
  printf("\n\nMAIN MENU\n1.INSERTION\n2.DELETION\n3.DISPLAY\n4.EXIT");
  printf("\n\nENTER YOUR CHOICE : ");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:
   printf("\n\nENTER THE QUEUE ELEMENT : ");
   scanf("%d",&num);
   add(num);
   break;
  case 2:
   del();
   break;
  case 3:
     display();
      break;
  case 4:
      exit(0);
  default: printf("\n\nInvalid Choice . ");
  }

 }
}


void add(int item)
{
 if(front ==(rear+1)%MAXSIZE)
 {
 printf("\n\nCIRCULAR QUEUE IS OVERFLOW");
 }
 else
 {
  if(front==-1)
    front=rear=0;
    else
    rear=(rear+1)%MAXSIZE;
    cq[rear]=item;
    printf("\n\nRear = %d    Front = %d ",rear,front);
 }
}


void del()
{
int a;
if(front == -1)
 {
 printf("\n\nCIRCULAR QUEUE IS UNDERFLOW");
 }
 else
 {
  a=cq[front];
   cq[front]=0;
  if(front==rear)
  front=rear=-1;
  else
   front = (front+1)%MAXSIZE;
  printf("\n\nDELETED ELEMENT FROM QUEUE IS : %d ",a);
  printf("\n\nRear = %d    Front = %d ",rear,front);

 }
}

void display()
{
 int i;
 for(i=0;i<MAXSIZE;i++)
   printf("%d\t",cq[i]);
}
