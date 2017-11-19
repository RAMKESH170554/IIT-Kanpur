#include<stdio.h>
void merge(int a[], int p, int q, int r){
	int L[1000], R[1000], i, l=1, m=1;
	L[q-p+2] = 1000; R[r-q+1] = 1000;
	for(i = 1; i <= (q-p+1); i++){
	    L[i] = a[i-1+p];
	    }
	for(i=1; i<=(r-q); i++){
	    R[i] = a[q+i];
	    }
	    
	for( i =p; i <= r; i++){
	    if(L[l] <= R[m])
	      a[i] = L[l++];
	    else
	      a[i] = R[m++];
	    }
}
void mergeSort(int a[], int p, int r){
	if( p < r){
	 int q = (p + r) / 2;
	 mergeSort(a , p, q);
	 mergeSort(a, q+1, r);
	 merge(a, p, q, r);
	 }
}

int main(){
	int a[1000], n;
	scanf("%d",&n);
	for(int i = 1; i<= n; i++)
	   scanf("%d",&a[i]);
	mergeSort(a,1,n);
	for(int i = 1; i<= n; i++)
	   printf("%d ",a[i]);
 }


