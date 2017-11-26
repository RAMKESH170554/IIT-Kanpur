#include <stdio.h>
#include <stdlib.h>
float s[500][500];
int root[500][500];
void St(float p[],float q[],int i,int j)
{
    int r,l;  float c,sum1=0,sum2=0,min=500;
    for(l=i;l<=j;l++)
        sum1=sum1+p[l];
    for(l=i-1;l<=j;l++)
        sum2=sum2+q[l];
    for(r=i;r<=j;r++)
    {
        c =sum1+sum2+s[i][r-1]+s[r+1][j];
        if(c<min)
            {
                min=c;
                root[i][j]=r;
            }
    }
     s[i][j]=min;
}
void print_BST(int i,int j)
{
     if(i==j)
      {
          printf("(%d",i);
          return;
      }
     if(i>j)
      {
           printf("(");
           return;
      }

        printf("(%d",root[i][j]);
        print_BST(i,root[i][j]-1);
        printf(")");
        print_BST(root[i][j]+1,j);
        printf(")");
}
int main()
{
    int n,i,d,j;
    scanf("%d",&n);
    float p[n],q[n+1];
    for(i=1;i<=n;i++)
     scanf("%f",&p[i]);
    for(i=0;i<=n;i++)
     scanf("%f",&q[i]);

     for(i=1;i<=n+1;i++)
        {
            s[i][i-1]=q[i-1];
        }

    for(d=1;d<=n;d++)
    for(i=1;i<=n-d+1;i++)
    {
        j=i+d-1;
        St(p,q,i,j);
    }

    printf("%.2f\n",s[1][n]);

     print_BST(1,n);
     printf(")");
     return 0;
}
