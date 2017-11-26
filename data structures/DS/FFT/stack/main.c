#include <stdio.h>
#include <stdlib.h>
int s[10],top=0,max=10,x;
void push(int x)
{
    if(top==max)
        printf("overflow");
    else
    {
        top=top+1;
        s[top]=x;
    }
}
int pop()
{
    if(top==0)
        printf("underflow");
    else
    {
        int y=s[top];
        top=top-1;
        return y;
    }
}
int peek()
{
    return top;
}
void isEmpty()
{
    if(top==0)
        printf("yes");
    else
        printf("no");
}
int main()
{   int p,t;
    char ch;

   while(top!=max+1)
    { scanf("%c",&ch);
        switch(ch)
    {
        case 'a':scanf("%d",&x);
                push(x);
                 break;
        case 'b':p=pop();
               printf("%d",p);
                 break;
        case 'c':t=peek();
                printf("%d",t);
                 break;
        case 'd':isEmpty();
                break;
        default:break;
    }
    }
    return 0;
}
