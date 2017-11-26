#include <stdio.h>
#include <stdlib.h>
int x,head=1,tail=1,size=0,capacity=10,Q[10];
int isEmpty()
{
    if(size==0)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(size==capacity)
        return 1;
    else
        return 0;
}
void enqueue(int x)
{   if(isFull())
     printf("overflow");
     else{
            Q[tail]=x;
       tail=(tail+1)%capacity;
       size++;
     }
}
int dequeue()
{   if(isEmpty())
     printf("underflow");
    int y=Q[head];
    head=(head+1)%capacity;
    size--;
    return y;
}
int front()
{
    return head;
}
int rear()
{
    return tail;
}
int main()
{   int p,f,r;
    char ch;
    while(size!=capacity)
    {
        scanf("%c",&ch);
        switch(ch)
    {
        case 'a':scanf("%d",&x);
                 enqueue(x);
                 break;
        case 'b':p=dequeue();
               printf("%d",p);
                 break;
        case 'c':f=front();
                printf("%d",f);
                 break;
        case 'd':r=rear();
                printf("%d",r);
                break;
        default:break;
    }
    }
    return 0;
}
