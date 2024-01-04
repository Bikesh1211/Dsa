/* Quick Sort */
#include <stdio.h>
#include <conio.h>
void quicksort (int [], int, int);
int partition(int [], int, int);
int a[5] = {55,1,78,13,45};
 main( )
{
int i;
//clrscr( );
printf("\nQuick Sort\n");
printf("\nArray before sorting :");
for(i=0; i < 5; i++)
printf("%4d", a[i]);
quicksort(a, 0, 4);
printf("\nArray after sorting :");
for(i=0; i < 5; i++)
printf("%4d", a[i]);
getch( );
}
void quicksort (int a[], int lower, int upper)
{
int pivot;
if (upper > lower)
{
pivot= partition(a, lower, upper);
quicksort(a, lower, pivot-1);
quicksort(a, pivot+1, upper);
}
}
int partition(int a[], int lower, int upper)
{
int i, p, q, t;
p = lower + 1;
q = upper;
i = a[lower];
while (q >= p)
{
while(a[p] < i)
p++;
while(a[q] > i)
q--;
if (q > p)
{
t =a[p];
a[p] = a[q];
a[q] = t;
}
}
t = a[lower];
a[lower] = a[q];
a[q] = t;
return q;
}
