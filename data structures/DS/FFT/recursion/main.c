#include <stdio.h>
#include <stdlib.h>
void fft(int arr[],int n)
{
    int i,even[100],odd[100];
    if(n==1)
        return;
    for(i=0;i<n/2;i++)
    {
        even[i]=arr[i*2];odd[i]=arr[i*2+1];
    }
    fft(even,n/2);
    fft(odd,n/2);
    if(n==2)
    {
    for(i=0;i<n/2;i++)
        printf("%d %d ",even[i],odd[i]);
        printf("\n");
    }

}
int main()
{
    int n,arr[100],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        arr[i]=i;
    fft(arr,n);
    return 0;
}
