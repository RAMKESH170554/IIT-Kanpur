#include<stdio.h>

int partition(int A[], int p, int r){
	
	int x = A[r];
	int i = p, j;
	for(int j = p; j <= r-1; j++){
		if(A[j] <= x){
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i++;
		}
		
	}
	int temp = A[r];
	A[r] = A[i];
	A[i] = temp;
	
	return i;
}

int select(int A[], int p, int r, int k){
	int q = partition(A,p,r);
	if(k == (q-p+1))
	 return A[q];
	if(k < (q-p+1))
	 select(A,p,q-1,k);
	else
	 select(A, q+1, r, k-q+p-1);
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int A[1000];
	for(int i =1; i<=n; i++){
		scanf("%d",&A[i]);
	}
	printf("%d ",select(A,1,n,k));
	
	return 0;
}












