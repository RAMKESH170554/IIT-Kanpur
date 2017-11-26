#include <stdio.h>
#include <stdlib.h>
float s[100][100];
int root[100][100];
void St(float p[],int i,int j)
{
    if(i>j) s[i][j]= 0;
    else
    {
        int r,l;  float c,sum=0,min=100;
    for(l=i;l<=j;l++)
        sum+=p[l];
    for(r=i;r<=j;r++)
    {
        c =sum+s[i][r-1]+s[r+1][j];
        if(c<min)
            {
                min=c;
                root[i][j]=r;
            }
    }
    s[i][j]=min;
    }
}
int main()
{
    int i,j,n,d;
    scanf("%d",&n);
    int k[n+1]; float p[n+1];
    for(i=1;i<=n;i++)
    scanf("%d%f",&k[i],&p[i]); // k[i]'s are in increasing order

    for(i=1;i<=n;i++)
        s[i][i]=p[i];

    for(d=1;d<=n-1;d++)
    for(i=1;i<=n-d;i++)
    {
        j=i+d;
        St(p,i,j);
    }
    printf("%f %d",s[1][n],root[1][n]);
    return 0;
}
