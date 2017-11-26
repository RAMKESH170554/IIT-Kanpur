#include <stdio.h>
void swap(int* x,int* y)
{
    int temp= *x;
    *x= *y;
    *y= temp;
}
void SelectionSort(int A[],int n)
{
   int i,j,min_ind;
    for(i=0;i<n-1;i++)
    {
        min_ind=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min_ind])
            min_ind=j;
        }
        swap(&A[min_ind],&A[i]);
    }

}
int main() {
	int Arr[20],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
    scanf("%d",&Arr[i]);
	SelectionSort(Arr,n);
	for(i=0;i<n;i++)
	printf("%d ",Arr[i]);
	return 0;
}
