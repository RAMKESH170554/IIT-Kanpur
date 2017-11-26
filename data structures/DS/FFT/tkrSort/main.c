#include <stdio.h>
#include <stdlib.h>
int x;
void swap(int* a,int* b)
{
    int t=*a;
        *a=*b;
        *b=t;
}
void tkrSort(int A[],int n)
{
    int p1=0,p2=n-1;
    while(p1<p2)
    {
        if(A[p1]<=x) p1++;
        else if(A[p2]>x)  p2--;
         else swap(&A[p1],&A[p2]);
    }
}
int main()
{
    int n,i;
    scanf("%d%d",&x,&n);
    int Arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&Arr[i]);
    tkrSort(Arr,n);

    for(i=0;i<n;i++)
        printf("%d ",Arr[i]);
    return 0;
}
