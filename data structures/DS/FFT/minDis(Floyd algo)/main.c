#include <stdio.h>
#include <stdlib.h>
int D[10][10];
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
void min_dis(int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
       D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
    }
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&D[i][j]);
    min_dis(n);
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
           printf("%d ",D[i][j]);//All pairs shortest path
       }
       printf("\n");
    }
    return 0;
}
