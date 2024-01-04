#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct dnode
{
	int info;
	struct dnode *left,*right;
}*head=NULL,*tail=NULL;
void create()
{
	char ch;
	struct dnode *ptr=NULL;
	do{
	ptr=(struct dnode *)malloc(sizeof(struct dnode));
	printf("enter data\n");
	scanf("%d",&ptr->info);
	ptr->left=NULL;
	ptr->right=NULL;
	if(head==NULL)
	{
		head=ptr;
		tail=ptr;
	}
	else 
	{
		tail->right=ptr;
		ptr->left=tail;
		tail=ptr;
	}
	printf("any more node y/n");
	fflush(stdin);
	ch=getchar();
}while(ch=='y');
	//free(ptr);
}


void ftraverse()
{
	struct dnode *ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		printf(" %u | %d| %u\t",ptr->left,ptr->info,ptr->right);
		ptr=ptr->right;
	}
}
void btraverse()
{
	struct dnode *ptr=NULL;
	ptr=tail;
	while(ptr!=NULL)
	{
		printf(" %u | %d | %u->\t",ptr->left,ptr->info,ptr->right);
		ptr=ptr->left;
		
	}
}
void ins_beg()
{
	struct dnode *ptr1=NULL;
	ptr1=(struct dnode *)malloc(sizeof(struct dnode));
	printf("enter data\n");
	scanf("%d",&ptr1->info);
	ptr1->left=NULL;
	ptr1->right=NULL;
	ptr1->right=head;
	head->left=ptr1;
	head=ptr1;
	//free(ptr1);
}
void ins_end()
{
		struct dnode *ptr2=NULL;
	ptr2=(struct dnode *)malloc(sizeof(struct dnode));
	printf("enter data\n");
	scanf("%d",&ptr2->info);
	ptr2->left=NULL;
	ptr2->right=NULL;
  ptr2->left=tail;
  tail->right=ptr2;
  tail=ptr2;
  //free(ptr2);
}
void ins_mid()
{
		struct dnode *ptr3=NULL,*t=NULL,*loc=NULL;
		int m;
	ptr3=(struct dnode *)malloc(sizeof(struct dnode));
	printf("enter data\n");
	scanf("%d",&ptr3->info);
	ptr3->left=NULL;
	ptr3->right=NULL;
	printf("enter markdata\n");
	scanf("%d",&m);
	loc=head;
	while(loc->info!=m)
	loc=loc->right;
	t=loc->right;
	loc->right=ptr3;
	ptr3->left=loc;
	ptr3->right=t;
	t->left=ptr3;
	//free(ptr3);
}
main()
{
	int ch;
	while(1)
	{
		printf("\n1 for creation\n");
		printf("2 for ftraverse\n");
		printf("3. for btraverse\n");
		printf("4. for insert at beginning \n");
		printf("5. for insert at the end \n");
		printf("6. for insert at the midddle\n");
		printf("7. for exit\n");
		printf("enter the value of choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				ftraverse();
				break;
			case 3:
				btraverse();
				break;
			case 4:
				ins_beg();
				break;
			case 5:
				ins_end();
				break;
			case 6:
				ins_mid();
				break;
			case 7:
				exit(0);
			default:
				printf("invalid choices");
				
				
		}
	}
}
