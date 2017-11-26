#include <stdio.h>
#include <stdlib.h>
    int c[10][10],A[10][10];
int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
void board(int m,int n)
{   if(m==0 || n==0)
       return;

    if(A[m][n]==A[m][n-1]+c[m][n])
    {
        board(m,n-1);
        printf("%d,%d ",m,n);
    }
    else
    {
        board(m-1,n);
        printf("%d,%d ",m,n);
    }
}
int main()
{
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
     for(j=1;j<=n;j++)
       scanf("%d",&c[i][j]);

    for(i=0;i<=m;i++)
    for(j=0;j<=n;j++)
        A[i][j]=0;

    for(i=1;i<=m;i++)
     for(j=1;j<=n;j++)
        A[i][j]=(max(A[i][j-1],A[i-1][j]))+c[i][j];

     printf("%d\n",A[m][n]);
     board(m,n);
     return 0;
}
