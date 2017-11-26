#include <stdio.h>
#include <stdlib.h>
int s[100],top=0,max=100;
void push(char ch)
{
    if(top==max)
        printf("overflow");
    else
    {
        top=top+1;
        s[top]=ch;
    }
}
char pop()
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

int main()
{
    char c[100]; int i=0,m=1,k,l;
    gets(c);
    while(c[i]!= NULL)
    {
        printf("%c",c[i]);
        i++;
    } i=0;
    while(c[i]!= NULL)
    {
        if(c[i]==' ')
            m++;
        i++;
        push(c[i]);
    }
    printf("\n%d\n",m);

    char* ch1=(char*)malloc(100*sizeof(char)); int j=0;
    int p=top;
    while(top!=0)
    {
        ch1[j]=pop();
        printf("%c",ch1[j]); j++;

    }
    printf("\n");
    top=p;
    for(l=0;l<m;l++)
   {   char* ch=(char*)malloc(10*sizeof(char)); int j=1;
       while(top!=0)
    {
       ch[j]= pop();
       if(ch[j]==' ')
       goto skip;
       j++;
    }
    skip:
    for(k=j;k>0;k--)
        printf("%c",ch[k]);
        printf(" ");
   }
    return 0;
}
