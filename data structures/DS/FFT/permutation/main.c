#include <stdio.h>
int n;
void kd(int s[],int i,int j)
{
    int k=1,r;
    if(i==n)
    {
        for(r=0;r<j;r++)
        printf("%d",s[r]);
        printf("\n");
        return;
    }
    while(k<=n)
    {
        s[i]=k;
        kd(s,i+1,j+1);
        k++;
    }
}
int main()
{
    int s[1000];
    scanf("%d",&n);
    kd(s,0,0);
        return 0;
}

