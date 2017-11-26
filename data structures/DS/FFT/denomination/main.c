#include <stdio.h>
#include <stdlib.h>
int t[]={1,2,5,10,20,50,100,500,2000},a[5000];
// t[1]=1,t[2]=2,t[3]=5,t[4]=10;t[5]=20,t[6]=50,t[7]=100,t[8]=500,t[9]=2000;
int min(int a,int b)
{
    if(a<=b)
        return a;
    else
        return b;
}
int mini(int x)
{
    int tmp=a[x];

    if(tmp>-1)
        return tmp;
    else
    {
        int Cmin=x+1;  int i=1;
        while(i<=9 && x>=t[i])
        {
            tmp = mini(x-t[i])+1;
            Cmin = min(tmp,Cmin);
            i++;
        }
        a[x]=Cmin;
    }
    return a[x];
}
void coins(int x)
{
    int i,j=a[x];
    while(j>1)
    {    i=0;
         while(i<9 && x>=t[i])
       {
          // tmp=a[x-t[i]];
          if( a[x-t[i]]==a[x]-1)
          {
              printf("%d ",t[i]);
              x=x-t[i];
              break;
          }
          i++;
       }
       j--;
    }
    printf("%d\n",x);
    return ;
}
int main()
{
    int x,i,p,y,z=0;
    scanf("%d",&x);
    for(i=0;i<5000;i++)
        a[i]=-1;
    a[0]=0;  a[1]=a[2]=a[5]=a[10]=a[20]=a[50]=a[100]=a[500]=a[2000]=1;

    p=mini(x);
    printf("%d\n",p);
   /* for(i=1;i<=9;i++)
    {   y=x;
        while(a[y]!=1 && y>z)
        {y=y-t[i];}
        z=y;
        if(y<t[i])
        {
            y=y+t[i];
            break;
        }
        while(y!=x && a[y]>=1)
        {
            a[y+t[i]]=a[y]+1;
            y=y+t[i];
        }
    }
     printf("%d\n",a[y]);*/
    coins(x);
   /* for(i=1;i<=9;i++)
    {
        while(x>t[i])
        {
            if(a[x]==a[x-t[i]]+1)
            {
                printf("%d ",t[i]);
                x=x-t[i];
            }
        }
        if(x==t[i])
        {
            printf("%d",t[i]);
            break;
        }
    }*/
    return 0;
}
