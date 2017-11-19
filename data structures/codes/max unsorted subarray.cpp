// Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] 
// such that sorting this subarray makes the whole array sorted.

#include <stdio.h>

void sort(int a[], int n){
    int l=0,r=0,i,j;
    for(i = 0; i< n-1 ;i++){    // assume increasing array
        if(a[i+1] <= a[i]){
            l = i;
            //printf("%d  %d  ",l,a[l]);
            break;
        }
    }
    for(i=(n-1); i>=1; i--){
        if(a[i]  <= a[i-1]){
            r = i;
            //printf("%d   %d  ",r, a[r]);
            break;
        }
    }
    int max = a[r], min = a[l];
    for(i = l; i <= r; i++){
        if(a[i] <= min)
         min = a[i];
        if(a[i] >= max)
         max = a[i];
    }
           // printf("%d  %d   ",max, min);
    for(i = 1;i >= 0;i++){
        if((l == 0) || (r == n-1))
         break;
        if(a[l-1] >= min)
         l--;
        if(a[r+1] <= max)
         r++;
        if((a[l] > min)&&(a[r] < max))
         break;
    }
    printf("%d  %d",l,r);
        
}

int main() {
    int a[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int n = sizeof(a)/sizeof(a[0]);
	sort(a,n);
	//code
	return 0;
}
