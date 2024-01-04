/* PROGRAM TO CREATE AND TRAVERSE A BINARY SEARCH TREE */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tnode
{
int info;
struct tnode *l;
struct tnode *r;
} ;//node;
struct tnode *root;

void create( )
{
int n, i;
struct tnode *newn, *ptr, *pptr;
printf("\n Enter no of nodes:\n");
scanf ("%d", &n);
printf("\n Enter %d values\n", n);
root=(struct tnode *) malloc(sizeof(struct tnode));
root->l=root->r=NULL;
scanf("%d",&root->info);
for(i=2;i<=n;i++)
{
newn=(struct tnode *)malloc(sizeof(struct tnode));
newn->l=newn->r=NULL;
scanf("%d",&newn->info);
ptr=root;
while(ptr!=NULL)
{
pptr=ptr;
if(newn->info<ptr->info)
{
ptr=ptr->l;
if(ptr==NULL)
pptr->l=newn;
}
else
{
ptr=ptr->r;
if(ptr==NULL)
pptr->r=newn;
}
}
}
}
void preorder(struct tnode *ptr)
{
if(ptr!=NULL)
{
printf("%d ,",ptr->info);
preorder(ptr->l);
preorder(ptr->r);
}
}
void inorder(struct tnode*ptr)
{
if(ptr!=NULL)
{
inorder(ptr->l);
printf("%d ,",ptr->info);
inorder(ptr->r);
}
}
void postorder(struct tnode*ptr)
{
if(ptr!=NULL)
{
postorder(ptr->l);
postorder(ptr->r);
printf("%d ,",ptr->info);
}
}
main()
{
//clrscr();
create();
printf("\n Preorder traversal:\n");
printf("\n");
preorder(root);
printf("\n inorder traversal:\n");
printf("\n");
inorder(root);
printf("\n postorder traversal:\n");
printf("\n");
postorder(root);
getch();
}
