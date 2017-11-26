#include <stdio.h>
void Merge(int Arr[],int p, int mid,int q)
{
    int i,j,k;
    int n1=mid-p+1;
    int n2=q-mid;
    int L[n1+1],R[n2+1];
    for(i=0;i<n1;i++)
    L[i]=Arr[p+i];
    for(j=0;j<n2;j++)
    R[j]=Arr[mid+j+1];
    L[n1]=1000; R[n2]=1000;
    i=0,j=0;
    for(k=p;k<=q;k++){
    if(L[i]<=R[j])
    {
        Arr[k]=L[i];
        i++;
    }
    else
    {
        Arr[k]=R[j];
        j++;
    }
    }
}
void MergeSort(int Arr[],int p,int q)
{
    if(p==q)
    return;
    else{
        int mid=(p+q)/2;
        MergeSort(Arr,p,mid);
        MergeSort(Arr,mid+1,q);
        Merge(Arr,p,mid,q);
    }
}

int main() {
	int A[50],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	MergeSort(A,0,n-1);
	for(i=0;i<n;i++)
	printf("%d ",A[i]);
	return 0;
}

