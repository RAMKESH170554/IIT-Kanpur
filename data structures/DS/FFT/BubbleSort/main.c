#include <stdio.h>
void BubbleSort(int A[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
     for(j=0;j<n-i-1;j++)
         if(A[j+1]<A[j])
            {
                int t= A[j];
                A[j]= A[j+1];
                A[j+1]= t;
            }
}
int main(void) {
	int Arr[15],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
    scanf("%d",&Arr[i]);
	BubbleSort(Arr,n);
	for(i=0;i<n;i++)
	printf("%d ",Arr[i]);
	return 0;
}

