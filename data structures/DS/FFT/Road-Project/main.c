#include <stdio.h>
#include <stdlib.h>
int N,s=1;
void DFS(int e[][N+1],char c[])
{
}
int main()
{
    int M,i,j,k,p;
    scanf("%d%d",&N,&M);
    int e[N+1][N+1];
    for(i=1;i<=N;i++)
    for(j=1;j<=N;j++)
       e[i][j]=0;

    for(k=1;k<=M;k++)
    {
        scanf("%d%d%d",&i,&j,&p);
        e[i][j]=p;
        e[j][i]=p;
    }
    char check[N+1];
    for(i=1;i<=N;i++)
       check[i]='F';

    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
           printf("%d ",e[i][j]);
        }
        printf("\n");
    }
    DFS(e,check);
    return 0;
}
