#include<stdio.h>

int ctr = 0;
int b[1000];

void merge(int a[], int p, int q, int r){
	int L[1000], R[1000], i, l=1, m=1;
	L[q-p+2] = 1000; R[r-q+1] = 1000;
	for(i = 1; i <= (q-p+1); i++){
	    L[i] = a[b[i-1+p]];
	    }
	for(i=1; i<=(r-q); i++){
	    R[i] = a[b[q+i]];
	    }
	    
	for( i =p; i <= r; i++){
	    if(L[l] <= R[m])
	      a[b[i]] = L[l++];
	    else{
	    ctr++;
	    	if(L[l] == 1000)
	    		ctr-- ;
	      a[b[i]] = R[m++];
	    }
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
	for(int i = 1; i<= n; i++)
	   scanf("%d",&b[i]);
	mergeSort(a,1,n);
//	for(int i = 1; i<= n; i++)
//	   printf("%d ",a[i]);
	printf("\n%d",ctr);
 }


