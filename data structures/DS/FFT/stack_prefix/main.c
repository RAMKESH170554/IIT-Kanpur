#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int s[20],top=0,max=20,x;
char str[30];
void push(char x)
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
        char y=s[top];
        top=top-1;
        return y;
    }
}
float eval()
{
    char z=pop();
    if(z!='+'&&z!='-'&&z!='/'&&z!='*')
        return (z-48);
    else
    {
        float a=eval();
        float b=eval();
        if(z=='+') return a+b;
        else
            if(z=='-') return a-b;
        else
            if(z=='*') return a*b;
        else
            if(z=='/') return a/b;
    }
}
int main()
{
    scanf("%s",str);
    int i=0;
    while(str[i]!='\0')
    {
        push(str[i]);  i++;
    }
    float y=eval();
    printf("%.1f",y);
    return 0;
}
