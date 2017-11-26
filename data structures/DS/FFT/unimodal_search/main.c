#include <stdio.h>
int Unimodal(int A[],int s,int e)
{   int mid;
    mid=(s+e)/2;
    if(s==e)
        return A[mid];

    if(A[mid+1]>A[mid])
        Unimodal(A,mid+1,e);
        else
        Unimodal(A,s,mid);
}
int main()
{
    int Arr[30],n,i,max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&Arr[i]);
    max=Unimodal(Arr,0,n-1);
    printf("%d",max);
    return 0;
}
