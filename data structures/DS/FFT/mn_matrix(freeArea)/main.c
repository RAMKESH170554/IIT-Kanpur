#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,x,k,l,p,r;
    scanf("%d%d%d",&m,&n,&x);
    int i[x],j[x],A[m][n];
    for(p=0;p<x;p++)
    scanf("%d%d",&i[p],&j[p]);

    for(k=0;k<m;k++)
    for(l=0;l<n;l++)
    A[k][l]=0;

    for(p=0;p<x;p++)
    A[i[p]][j[p]]=-1;

    if(m<=n) p=m;
    else p=n;

    int k1=0,l1=0,M=0;
    for(r=0;r<=p-2;r++)
    {
        int k,l,k2,l2,m1=-1;
        for(k=0;k<m-1;k++)
      {
        int m2=-1;
        for(l=0;l<n-1;l++)
       {
         if(A[k][l]==r && A[k][l+1]==r && A[k+1][l]==r && A[k+1][l+1]==r)
         {
           A[k][l]=r+1;
         }
         if(A[k][l]>m2)
            {
               m2=A[k][l];
               k2=k; l2=l;
            }
       }
       if(m2>m1)
       {
          m1=m2;
          k1=k2; l1=l2;
       }
     }
     M=m1;
    }
    int c=0;
    for(k=0;k<m;k++)
       for(l=0;l<n;l++)
          if(A[k][l]==0)
            {
                c++;
                break;
            }

    if(c==0)
        printf("0");
    else
        printf("%d %d %d %d",k1,l1,k1+M,l1+M);
    return 0;
}
