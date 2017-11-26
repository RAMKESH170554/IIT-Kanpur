#include <stdio.h>
#include <stdlib.h>
int c[100],v[100],k[100][500];
int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
int kp(int i,int j)
{
    if(i==0) return 0;
    if(j==0) return 0;

    if(j-c[i]>=0)  return max(k[i-1][j],k[i-1][j-c[i]]+v[i]);
    else return k[i-1][j];
}
void sort(int A[],int n)
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
void output(int n,int C)
{
   // int *a=(int *)malloc(n*sizeof(int))
   int a[n],i ,j=0;
     while (n>0)
    {
      if(C-c[n]>=0)
     {
        if(k[n][C]==k[n-1][C-c[n]]+v[n])
        {
            //printf("%d ",c[n]);
            j++; a[j]=c[n];
            C=C-c[n];
        }
      }
       n--;
    }
    sort(a,j);
    for(i=1;i<=j;i++)
        printf("%d ",a[i]);
}
int main()
{
    int n,C,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d%d",&c[i],&v[i]);
    scanf("%d",&C);

    for(i=1;i<=n;i++)
    for(j=1;j<=C;j++)
     k[i][j]=kp(i,j);

    output(n,C);
    return 0;
}
