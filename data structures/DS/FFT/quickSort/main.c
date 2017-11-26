#include <stdio.h>
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int part(int A[],int p, int r)
{
    int pivot=A[r],j,i=p-1;
    for(j=p;j<r;j++)
    {
        if(A[j]<=pivot)
            { swap(&A[j],&A[i+1]);
              i++;
            }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}
void quickS(int A[],int p,int r)
{
    if(p<r)
    {
        int q =part(A,p,r);
        quickS(A,p,q-1);
        quickS(A,q+1,r);
    }

}
int main()
{
    int n,A[20],i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&A[i]);
    quickS(A,1,n);
    for(i=1;i<=n;i++)
        printf("%d",A[i]);
    return 0;
}
