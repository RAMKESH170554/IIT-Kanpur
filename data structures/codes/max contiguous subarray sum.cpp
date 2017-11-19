#include<stdio.h>

int crossing_mid(int A[], int p, int q, int r){
	int sum = 0;
	int lsum = -10000;
	for(int i = q; i >= p; i--){
		sum += A[i];
		if( lsum < sum)
		 lsum = sum;
	}
	sum = 0;
	int rsum = -10000;
	for(int i = q+1; i <= r; i++){
		sum += A[i];
		if( rsum < sum)
		 rsum = sum;
	}
	return (rsum + lsum);
}

int max_sum_contig(int A[], int p, int r){
	if(p == r)
	 return A[p];
	else{
	int q = (p+r)/2 ;
	int lefts = max_sum_contig(A, p, q);
	int rights = max_sum_contig(A, q+1, r);
	int t = crossing_mid(A,p,q,r);

	if((lefts <= t)&&(rights <= t))
	return t;
	else if((lefts >= t)&&(rights <= lefts))
	return lefts;
	else
	return rights;
	}
}
/*
16
13 -3 -25 20 -3 -16 -23 18 20 -7 12 -5 -22 15 -4 7
*/
int dynamic_contig(int A[], int n){
	int C[1000] = {0} , i,k,max = 0;
	C[1] = A[1];
	for(i= 1; i <= n; i++){
	
		if((A[i+1]+C[i]) >= C[i+1]){
		 C[i+1] = A[i+1]+C[i];
	
		 if(max < C[i+1]){
		  max = C[i+1];
		  k = i+1;
		}
	}
//		else
//		 C[i+1] = A[i+1];
	}
	return C[k];
}

int main(){
	int n;
	scanf("%d",&n);
	int A[1000];
	for(int i =1; i<=n; i++){
		scanf("%d",&A[i]);
	}
int a = max_sum_contig(A,1,n);
int b = dynamic_contig(A,n);
	//for(int i=1;i <= n; i++)
		printf("%d %d",a,b);

	
	return 0;
}
