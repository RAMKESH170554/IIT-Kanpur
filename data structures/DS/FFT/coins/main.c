#include <stdio.h>
#include <stdlib.h>
int c[100];
int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
void coins(int n,int a[])
{
    if(n==0) return;
    if(n==1)
    {
        printf("%d ",c[1]);
        return;
    }
    if(a[n]==a[n-1])
     coins(n-1,a);
    else
      {
          coins(n-2,a);
          printf("%d ",c[n]);
      }
}
int main()
{
    int i,n;
     scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }

    int a[n];
    a[0]=0; a[1]=c[1];
    for(i=2;i<=n;i++)
    {
        a[i]=max(c[i]+a[i-2],a[i-1]);
    }

       coins(n,a);
    return 0;
}
