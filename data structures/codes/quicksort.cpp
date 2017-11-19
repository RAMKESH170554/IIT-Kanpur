#include<stdio.h>
#include<stdlib.h>

int partition(int A[], int p, int r){
	int h = rand()%(r-p+1)+p ;
	int x = A[h];
	int temp = A[h];
	A[h] = A[r];
	A[r] = temp;
	int i = p, j;
	for(int j = p; j <= r-1; j++){
		if(A[j] <= x){
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i++;
		}
		
	}
	temp = A[r];
	A[r] = A[i];
	A[i] = temp;
	
	return i;
}

void variant_partition(int A[], int p, int r){
	
	int x = A[r];
	int i = p, j = p, k = r;
	while(j != k){
		if(A[j] < x){
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i++;
		}
		if(A[j] > x){
			int temp = A[j];
			A[j] = A[k];
			A[k] = temp;
			k--;j--;
		}
		j++;
	}
//	int temp = A[k];
//	A[k] = A[i];
//	A[i] = temp;
	printf("%d %d\n",i,k);
	for(int i =p; i<= r; i++){
		printf("%d ",A[i]);
	}
	//return i;
}


void quick_sort(int A[], int p, int r){
	
	if(p < r){
		int q = partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int A[1000];
	for(int i =1; i<=n; i++){
		scanf("%d",&A[i]);
	}
	variant_partition(A,1,n);
	printf("\n");
	quick_sort(A,1,n);
	for(int i =1; i<= n; i++){
		printf("%d ",A[i]);
	}
	
	return 0;
}
