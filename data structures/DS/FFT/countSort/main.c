#include <stdio.h>
#include <stdlib.h>
#define k 10
void countSort(int A[],int n)
{
    int B[n],C[k],i;
    for(i=0;i<k;i++)
        C[i]=0;
    for(i=0;i<n;i++)
       C[A[i]]=C[A[i]]+1;
    for(i=1;i<k;i++)
        C[i]=C[i]+C[i-1];
    for(i=0;i<n;i++)
        { B[C[A[i]]]=A[i];
          C[A[i]]=C[A[i]]-1;
        }
    for(i=1;i<=n;i++)
        printf("%d ",B[i]);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int Arr[n];
    for(i=0;i<n;i++)
    scanf("%d",&Arr[i]);
    countSort(Arr,n);
    return 0;
}
