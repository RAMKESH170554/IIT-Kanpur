#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    FILE *p2;
   // printf("Data Input\n");
   // p1=fopen("Input","w");
   // while((c=getchar())!=EOF)
   // {
   //     putc(c,p1);
   // }
   // fclose(p1);
    printf("\nData Output\n");
    p2=fopen("Input","r");
    while((c=getc(p2))!=EOF)
    {
        putchar(c);
    }
    fclose(p2);
    return 0;
}
