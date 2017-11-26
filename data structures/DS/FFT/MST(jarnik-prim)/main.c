#include <stdio.h>
#include <stdlib.h>
int V[100],E[1000],n,aaa[1000][1000];
void swap(int *p, int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}
void heapify(int A[],int k,int i)
{
    int l=2*i, r=2*i+1;
    int smlst=i;
    if(l<=k && A[l]<A[i])
     smlst=l;
    if(r<=k && A[r]<A[smlst])
     smlst=r;
    if(i!=smlst)
        {swap(&A[smlst],&A[i]);
        // heapify(A,k,smlst);
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
int Extract_min(int A[],int k)
{
    build_heap(A,k);
    int x=A[1];
    return x;
}

void MST(int e[][n+1])
{
    int i,j,l,r,p=0,k=0,x=1;
    for(i=1;i<n;i++)
    {
        p++;  V[p]=x;
       for(j=1;j<=n;j++)
       {
           k++;
           E[k]=e[x][j];
       }
       int min=Extract_min(E,k);

       for(r=1;r<=p;r++)
       {
           for(j=1;j<=n;j++)
           {
               if(min==e[V[r]][j])
              {
                  aaa[V[r]][j]=1;
                  aaa[j][V[r]]=1;
                    x=j;
                   goto tkr;
              }
           }
        }
        tkr:
        for(r=1;r<=p;r++)
        {
            e[x][V[r]]=999;
            e[V[r]][x]=999;
        }
        for(r=1;r<=p;r++)
        {
            for(l=n*r-n+1;l<=n*r;l++)
           {
               E[l]=e[V[r]][l-n*r+n];
           }
        }
    }
}
int main()
{
    int i,j,p;
    scanf("%d",&n);//n==|V|
    int e[n+1][n+1];
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        e[i][j]=999;
        aaa[i][j]=0;
    }


    while((scanf("%d%d%d",&i,&j,&p))!=EOF)
    {
        e[i][j]=p;
        e[j][i]=p;
    }

     MST(e);
     for(i=1;i<=n;i++)
    for(j=i;j<=n;j++)
    {
        if(aaa[i][j]==1)
        {

            printf("%d %d\n",i,j);
        }
    }
    return 0;
}
