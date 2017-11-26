#include <stdio.h>
int Left(int i)
{
    return 2*i;
}
int Right(int i)
{
    return (2*i+1);
}
void swap(int *p, int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}
void heapify(int A[],int n,int i)
{
    int l=Left(i), r=Right(i);
    int lrgst=i;
    if(l<=n && A[l]>A[i])
     lrgst=l;
    if(r<=n && A[r]>A[lrgst])
     lrgst=r;
    if(i!=lrgst)
        {swap(&A[lrgst],&A[i]);
         //heapify(A,n,lrgst);
        }
}
void HeapSort(int A[],int n)
{
    int j;
    for(j=n/2;j>=1;j--)
    {
        heapify(A,n,j);
    }
    while(n>1)
    {
     swap(&A[n],&A[1]);
     n=n-1;
     heapify(A,n,1);
    }
}
int main()
{
    int A[20],i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&A[i]);
    HeapSort(A,n);
    for(i=1;i<=n;i++)
    printf("%d ",A[i]);
    return 0;
}
