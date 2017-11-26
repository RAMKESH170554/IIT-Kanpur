#include <stdio.h>
#include <stdlib.h>
int n,V[100],p=1,e[100][100];
void swap(int *y, int *z)
{
    int temp=*y;
    *y=*z;
    *z=temp;
}
void heapify(int A[],int k,int i)
{
    int l=2*i, r=2*i+1;
    int lrgst=i;
    if(l<=k && A[l]>A[i])
     lrgst=l;
    if(r<=k && A[r]>A[lrgst])
     lrgst=r;
    if(i!=lrgst)
        {swap(&A[lrgst],&A[i]);
         heapify(A,k,lrgst);
        }
}
void build_heap(int A[],int k)
{
   int j;
    for(j=k/2;j>=1;j--)
    {
        heapify(A,k,j);
    }
}
int Extract_max(int A[],int k)
{
    build_heap(A,k);
    int x=A[1];
    return x;
}

void MST(int x)
{
    int i,j,max=0;
    for(i=p-2;i>=1;i--)
    {   int k=0,m=0,E[n];
        if(e[V[p]][V[i]]!=999)
           {
              int y=p;
             //printf("it's a cycle\n");
             while(y>i)
             {
                k++;   E[k]=e[V[y]][V[y-1]];
                y--;
             }
              k++; E[k]=e[V[p]][V[i]];
              max=Extract_max(E,k);
              //printf("%d\n",max);
                int l=p;
              while(l>i)
             {
                if(e[V[l]][V[l-1]]==max)
                {
                   e[V[l]][V[l-1]]=-1;
                   e[V[l-1]][V[l]]=-1;
                   m=1;
                   goto tkr;
                }
                l--;
             }
                tkr:
                if(m==0)
                {
                    if(e[V[p]][V[i]]==max)
                    {
                      e[V[p]][V[i]]=-1;
                      e[V[i]][V[p]]=-1;
                    }
                }
                return;
           }
    }

     for(j=1;j<=n;j++)
    {
        int c=0;
        for(i=1;i<=p;i++)
        {
            if(j!=V[i])
              c++;
        }
        if(c==p)
        {
            if(e[x][j]!=999)
            {
               p++; V[p]=j;
               x=V[p];
               //for(i=1;i<=p;i++)
               //printf("%d\n",V[i]);
               MST(x);
            }
        }
    }
}
int main()
{
    int i,j,k;
    scanf("%d",&n);//n==|V|
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      e[i][j]=999;

    while((scanf("%d%d%d",&i,&j,&k))!=EOF)
    {
        e[i][j]=k;
        e[j][i]=k;
    }

    V[1]=2;
    MST(2);

    for(i=1;i<=n;i++)
    for(j=i;j<=n;j++)
    {
        if(e[i][j]!=999 && e[i][j]!=-1)
            printf("%d %d\n",i,j);
    }
    return 0;
}
