#include<stdio.h>
int B[20];
void sort(int Arr[],int n)
{
	int i,j;
      for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		 if(Arr[j+1]<Arr[j])
			{
				int t=Arr[j];
				    Arr[j]=Arr[j+1];
				    Arr[j+1]=t;
			}
    for(j=0;j<n;j++)
	printf("%d ",Arr[j]);

}
void bucket(int A[],int n)
{    int i,j;
	for(i=0;i<10;i++)
	{
		int k=0;
		for(j=0;j<n;j++)
		{
			if(A[j]<(i+1)*10&&A[j]>=10*i)
			{
				B[k]=A[j];
				k++;
			}
		}
			sort(B,k);
	}
}
int main()
{
	int n,A[20],j;
	scanf("%d",&n);
	for(j=0;j<n;j++)
	scanf("%d",&A[j]);
	bucket(A,n);
	return 0;
}

