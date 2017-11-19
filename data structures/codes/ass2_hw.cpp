#include<stdio.h>

int A[1000],B[1000],top = 0;

int main(){
	int n;
	scanf("%d",&n);
	A[0]= 1000;
//	B[1] = 1;
	for(int i = 1;i<= n;i++){
		scanf("%d",&A[i]);
		{
			top = i;
			while(A[top] <= A[i])
				top--;
		}
		B[i] = i - top;
	}
	for(int i = 1;i<= n;i++)
		printf("%d ",B[i]);
	return 0;
}
/*9 
1 5 8 4 65 45 123 84 98
*/
