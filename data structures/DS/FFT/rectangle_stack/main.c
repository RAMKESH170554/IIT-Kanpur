#include <stdio.h>
#include <stdlib.h>
int top=0,n;
struct A
{
    int x;
    int y;
}s[10];

void push(struct A p)
{
    top=top+1;
    s[top]=p;
}
void pop()
{
    top=top-1;
}
int Area(struct A a[])
{
    int i,ar=0;
    for(i=1;i<=n;i++)
    {
        while(a[i].y < s[top].y)
        {
            int r= (i-s[top].x)*(s[top].y);
            if(ar<r)  ar=r;
            if(a[i].y >s[top-1].y)
             s[top].y=a[i].y;
             else
             pop();
        }
        if(a[i].y > s[top].y)
            push(a[i]);
    }
    return ar;
}
int main()
{
    int i;
    scanf("%d",&n);
    struct A a[n];
    for(i=1;i<=n;i++)
    scanf("%d%d",&a[i].x,&a[i].y);

    s[0].x=0; s[0].y=0;
    int z=Area(a);
    printf("%d",z);
    return 0;
}
