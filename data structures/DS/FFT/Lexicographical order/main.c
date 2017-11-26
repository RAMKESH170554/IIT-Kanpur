#include <stdio.h>
#include <string.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    char s[n][100];
    for(i=0;i<n;i++)
        gets(s[i]);
    return 0;
}
