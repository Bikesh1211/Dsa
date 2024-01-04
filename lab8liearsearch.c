/* Implementation of linear Search */

#include<stdio.h>
#include<conio.h>
main()
{
int arr[20],n,i,data;
//clrscr();
printf("\nHow many elements you want to enter in the array:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter element %d:",i+1);
scanf("%d",&arr[i]);
}
printf("\n\nPress any key to continue...");
printf("\nEnter the element to be searched:");
scanf("%d",&data);

for(i=0;i<n;i++)
{
	if(data==arr[i])
	{
		printf("found at position=%d",i+1);
		break;
		
	}
}
if(i==n)
printf("not found");
getch();
}
