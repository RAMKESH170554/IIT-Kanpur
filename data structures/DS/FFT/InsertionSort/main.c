#include <stdio.h>
void InsertionS(int A[],int n)
{
    int i,j;
    for(j=2;j<=n;j++)
    {   int key=A[j];
        i=j-1;
        while((i>=1)&&(A[i]>key))
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}
int main()
{
    int n,A[20],i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&A[i]);
    InsertionS(A,n);
    for(i=1;i<=n;i++)
    printf("%d ",A[i]);
    return 0;
}
