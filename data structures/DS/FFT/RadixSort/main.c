#include <stdio.h>
#include <stdlib.h>
#define k 10
int c=10,d=0,m,Arr[20];
int* countSort(int A[],int n)
{
    int B[n],C[k],i;
    for(i=0;i<k;i++)   C[i]=0;
    for(i=0;i<n;i++)   C[A[i]]=C[A[i]]+1;
    for(i=1;i<k;i++)   C[i]=C[i]+C[i-1];
    for(i=0;i<n;i++)
        {
          B[C[A[i]]]=Arr[i];
          C[A[i]]=C[A[i]]-1;
        }
        for(i=0;i<n;i++)
        Arr[i]=B[i];
   return B;
}
void RadixSort(int A[],int n)
{    int i,r[n],*Y,X[n];
    if(d==m)
     return;
    else{
    for(i=0;i<n;i++)
        r[i]=A[i]%(10);
        d++;
     for(i=0;i<n;i++)
        printf("%d",r[i]);

    Y=countSort(r,n);
    for(i=0;i<n;i++)
        X[i]=Y[i]/(c); c=c*10;
    RadixSort(X,n);
    }
}
int main()
{
    int n,i;
    scanf("%d%d",&m,&n);

    for(i=0;i<n;i++)
    scanf("%d",&Arr[i]);
    RadixSort(Arr,n);

    for(i=0;i<n;i++)
     printf("%d ",Arr[i]);
    return 0;
}
