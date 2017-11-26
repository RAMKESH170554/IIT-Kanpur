#include <stdio.h>
#include <stdlib.h>
int A[10][10];
void warshall(int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
              if(A[i][j]==0)
              {
                  if(A[i][k]==1 && A[k][j]==1)
                    A[i][j]=1;
              }
            }
        }

    }
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&A[i][j]);
    warshall(n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
