#include <stdio.h>
#include <stdlib.h>
int V[100],E[1000],d[100],n,s;
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
         heapify(A,k,smlst);
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

void Slength(int e[][n],int p[])
{
    int i,j,x1=s,l,q=0,r,y,min,k=0;
    for(i=0;i<n-1;i++)
    {
        q++; V[q]=x1;
        for(j=0;j<n;j++)
        {
           k++;
           E[k]=e[x1][j];
           //printf("%d ",e[x1][j]);
        }
        printf("\n");
        min=Extract_min(E,k);
        //printf("%d\n",min);
        for(r=1;r<=q;r++)
        for(j=0;j<n;j++)
        {
            int x=j;
            if((d[V[r]]+e[V[r]][x])<d[x])
            {
                d[x]=d[V[r]]+e[V[r]][j];
                p[x]=V[r];
            }
            else
                if((d[V[r]]+e[V[r]][x])==d[x])
            {
                p[x]=V[r];
            }
        }

        for(r=1;r<=q;r++)
        for(j=0;j<n;j++)
        {
            if(min==e[V[r]][j])
            {
                y=j;
                goto tkr;
            }
        }
        tkr:
        for(r=1;r<=q;r++)
        {
            e[V[r]][y]=999;
            e[y][V[r]]=999;
        }

            x1=y;
           // printf("%d\n",x1);
         for(r=1;r<=q;r++)
         for(l=n*r-n;l<n*r;l++)
            {
                E[l]=e[V[r]][l-n*r+n];
                //printf("%d ",E[l]);
            }
    }
}
int main()
{
    int i,j,k,x,t;
    scanf("%d%d%d",&n,&s,&t);//n==|V| source destination
    int e[n][n],a[n];
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      e[i][j]=999;

    while(scanf("%d%d%d",&i,&j,&k)!=EOF)
    {
        e[i][j]=k;
        //e[j][i]=k;
    }
    int d[n],p[n];
    for(i=0;i<n;i++)
    {
        d[i]=999;
        p[i]=-1;
    }
    d[s]=0;

    Slength(e,p); //single source shortest path

     //for(i=0;i<n;i++)
    // printf("d[%d]=%d %d\n",i,d[i],p[i]);

      printf("%d\n",d[t]);

      x=t,i=0;
      while(x!=-1)
      {
          i++;
         a[i]=x;  x=p[x];
      }
      for(j=i;j>=1;j--)
      {
          printf("%d ",a[j]);
      }
    return 0;
}
