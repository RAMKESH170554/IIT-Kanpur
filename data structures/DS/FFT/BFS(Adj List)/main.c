#include <stdio.h>
#include <stdlib.h>
int x,head=1,tail=0,size=0,Q[100],n;
void enqueue(int x)
{
    tail=(tail+1);
    Q[tail]=x;
    size++;
}
int dequeue()
{
    int y=Q[head];
    head=(head+1);
    size--;
    return y;
}
int isEmpty()
{
    if(size==0)
        return 1;
    else
        return 0;
}
void BFS(int e[][n+1],int d[],int s)
{
    int v,w,n,j;
    enqueue(s);
    while(!isEmpty())
    {
        v=dequeue();
        for(j=1;j<=n;j++)
        {
            if(e[v][j]!=999)
            {
                w=j;
                if(d[w]==999)
                {
                    d[w]=d[v]+1;
                    enqueue(w);
                }
            }
        }
    }
}
int main()
{
    int i,j,s;
    scanf("%d%d",&n,&s);
    int e[n+1][n+1];
    while(scanf("%d%d",&i,&j)!=EOF)
    {
        e[i][j]=1;
        e[j][i]=1;
    }
    int d[n+1];
    for(i=1;i<=n;i++)
        d[i]=999;

    d[s]=0;
    BFS(e,d,s);
    j=0;
    while(j<n)
    {
        for(i=1;i<=n;i++)
        {
            if(d[i]==j)
            printf("%d ",i);
        }
        printf("\n");
        j++;
    }
    return 0;
}
