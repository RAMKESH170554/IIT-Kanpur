#include <stdio.h>
#include <stdlib.h>
float S(float p[],int i,int j)
{
    if(i==j) return p[i];
    if(i>j) return 0;

    int r,l;  float c,sum=0,min=100;
    for(l=i;l<=j;l++)
        sum+=p[l];
    for(r=i;r<=j;r++)
    {
        c =sum+S(p,i,r-1)+S(p,r+1,j);
        if(c<min)
            min=c;
    }
    return min;
}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    int k[n+1]; float p[n+1],B[n+1][n+1];
    for(i=1;i<=n;i++)
    scanf("%d%f",&k[i],&p[i]); // k[i]'s are in increasing order
    for(i=1;i<=n+1;i++)
    for(j=0;j<=n;j++)
      B[i][j]=S(p,i,j);

    for(i=1;i<=n+1;i++)
    {
        for(j=0;j<=n;j++)
           printf("%f ",B[i][j]);
           printf("\n");
    }
    return 0;
}
