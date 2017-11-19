#include<stdio.h>

int ctr;
int crossing_mid(int A[], int p, int q, int r){

	ctr = 0;
	for(int i = q; i > p; i--){
		
		if(A[i] >= A[i-1])
		 ctr++;
		else
		 break;
	}
	ctr++;
	for(int i = q+1; i < r; i++){
	
		if(A[i] <= A[i+1])
		 ctr++;
		else
		 break;
	}
	return ctr;
}

int longest(int A[], int p, int r){
	if(p == r)
	 return ctr;
	int q = (p+r)/2 ;
	int lefts = longest(A,p,q);
	int rights = longest(A,q+1,r);
	int t = crossing_mid(A,p,q,r);
	
	if((lefts <= t)&&(rights <= t))
	 return t;
	else if((lefts >= t)&&(rights <= lefts))
	 return lefts;
	else
	 return rights;
}

int main(){
	int n;
	scanf("%d",&n);
	int A[1000];
	for(int i =1; i<=n; i++){
		scanf("%d",&A[i]);
	}

	int b = longest(A,1,n);

		printf("%d ",b);

	
	return 0;
}
