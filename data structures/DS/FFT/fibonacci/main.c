#include <stdio.h>
#include <stdlib.h>
void F(int n,int f1,int f2)
{
    if(n>1)  F(n-1,f2,f1+f2);
    printf("%d ",f2);
}

/*int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    else{
        return fib(n-1)+fib(n-2);
    }
}
*/
int main()
{
    int n;
    scanf("%d",&n);
    F(n,0,1);
   // printf("%d",f);
    return 0;
}
