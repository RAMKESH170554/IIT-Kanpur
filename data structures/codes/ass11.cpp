#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<complex.h>

//                  link to ques 
//     http://www.spoj.com/problems/IITKESO207A_1P_1
//double _Complex y[1000];
double pi = 3.14159265358979323846;
int opt;

double _Complex* FFT(double _Complex a[], int n){
	if(n == 1) 
	return a;
	
	double _Complex w, ae[n/2], ao[n/2];
	double _Complex* ye;
	double _Complex* yo;
	double _Complex* y=(double _Complex*)malloc(n*sizeof(double _Complex));

	for(int i = 0; i < n/2; i++){
		ao[i] = a[2*i+1];
		ae[i] = a[2*i];
	}
	
 	ye = FFT(ae, n/2);
 	yo = FFT(ao, n/2);
	
	for(int i = 0; i < (n/2); i++){
		if(opt == 0)
		w = cos(2.0*pi*i/n) + I*sin(2.0*pi*i/n);
		else
		w = cos(2.0*pi*i/n) - I*sin(2.0*pi*i/n);
		
		y[i] = ye[i] + w * yo[i]; //creal(w * yo[i]) + I*cimag(w * yo[i]);
		y[i + n/2] = ye[i] - w * yo[i]; //creal(w * yo[i]) - I*cimag(w * yo[i]);
				
	}
	return y;
}
							 // 0 4 0 0 1.0 0 2.0 0 3.0 0
							 //  1 4 6.0 0 -2.0 -2.0 -2.0 0 -2.0 2.0
int main(){
	int n, k, t, l;
	double re, im, p, q;
	scanf("%d",&t);
	double _Complex* h[t];
	int op[t],on[t];
	for(l = 0; l<t;l++){
		
		scanf("%d %d",&opt,&n);
		op[l] = opt;
		on[l] = n;
		double _Complex a[n];
		for(k = 0; k<n; k++){
			scanf("%lf %lf",&re,&im);
			a[k] = re + im*I;
		}
		h[l] = FFT(a,n);
		// printf("%d", n);
	}
	for(l = 0; l<t;l++){
		for(k = 0; k < on[l]; k++){
			if(op[l] == 0)
			p = creal(h[l][k]), q = cimag(h[l][k]);
			else
			p = creal(h[l][k])/on[l], q = cimag(h[l][k])/on[l];
			printf("%.6lf %.6lf\n",p,q);
			/* if((abs(p) == 0.00)&&(abs(q) == 0.00)){
			printf(" %d %d",0,0);
			continue;
		}
			if(abs(p) == 0.00)
			printf(" %d %.1lf",0,q);
			else if(abs(q) == 0.00)
			printf(" %.1lf %d",p,0);
			else
			printf(" %.1lf %.1lf",p,q); */
		}
	}
	
	return 0;
}

