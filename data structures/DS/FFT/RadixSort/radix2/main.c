#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ab[100000],cd[100000];
void couning_sort(int a[],int n,int ab[],int d)
{
    int k=10;
    int i,j;
    int t[n],c[k];
    for(i=0;i<k;i++)
    {
        c[i]=0;
        for(j=0;j<n;j++)
        {
            if(a[j]==i)
            {
                c[i]=c[i]+1;
            }
        }
    }
    for(j=1;j<k;j++)
    {
        c[j]=c[j-1]+c[j];
    }

   for(j=n-1;j>=0;j--)
   {
       t[c[a[j]]-1]=ab[j];
       c[a[j]]=c[a[j]]-1;
   }
    for(i=0;i<n;i++)
    {
        ab[i]=t[i];
    }

}
void radix_sort(int ab[],int num,int digits)
{
    int b[num],i,j;
    for(i=0;i<digits;i++)
    {
        for(j=0;j<num;j++)
        {
            b[j]=cd[j]%10;

        }

        /*for(j=0;j<num;j++)
    	{
        printf("%d ",b[j]);
    	}
        printf("\n");

        */
        couning_sort(b,num,ab,i);
        for(j=0;j<num;j++)
        cd[j]=ab[j];
        for(j=0;j<num;j++)
        cd[j]=cd[j]/(pow(10,i+1));


    }

}

int main()
{
    int num,digits,i;
    scanf("%d %d",&num,&digits);
    for(i=0;i<num;i++)
    {
        scanf("%d",&ab[i]);
        cd[i]=ab[i];

    }
    radix_sort(ab,num,digits);
    for(i=0;i<num;i++)
    {
        printf("%d ",ab[i]);
    }


    return 0;
}
