#include<stdio.h>

void max_heapify(int A[], int i, int n){
	int r = 2*i+1, l = 2*i, max = i;  /// n = sizeof(a) / sizeof(int);
	
	if((l <= n) && (A[l] > A[i]))
	 max = l;
	if((r <=n)&&( A[r] >= A[max]))
	 max = r;
	if( max != i){
		int temp = A[max];
		A[max] = A[i];
		A[i] = temp;
		max_heapify(A,max,n);
	}
}

void build_heap(int A[], int n){
	//int n = A.heapsize;
	for(int i = (n/2); i>0 ; i--){
		max_heapify(A,i,n);
	}
}

void heap_sort(int A[],int n){
	build_heap(A,n);
	//int n = A.heapsize;
	int k = n;
	for(int i = n; i>1 ; i--){
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		max_heapify(A,1,--k);
	}
	
}

int main(){
	int n;
	scanf("%d",&n);
	int A[1000];
	for(int i =1; i<=n; i++){
		scanf("%d",&A[i]);
	}
	heap_sort(A,n);
	for(int i =1; i<= n; i++){
		printf("%d ",A[i]);
	}
	
	return 0;
}
