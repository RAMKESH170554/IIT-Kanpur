#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<complex.h>

struct comp{
	double re,im;
};
int opt;
double pi = 3.14159265358979323846;

struct comp* recursive_FFT(struct comp a[], int n){ /// 0 4 0 0 1.0 0 2.0 0 3.0 0
	if(n == 1){
		return a;
	}
	struct comp ae[n/2], ao[n/2],w,*ye,*yo;
	struct comp* y=(struct comp*)malloc(n*sizeof(struct comp));
	
	for(int i=0;i<n/2; i++){

		   ae[i].im = a[2*i].im;
		   ae[i].re = a[2*i].re;

		   ao[i].im = a[2*i+1].im;
		   ao[i].re = a[2*i+1].re;

	}
	
	ye = recursive_FFT(ae, n/2);
	yo = recursive_FFT(ao, n/2);

	for(int k = 0; k < (n/2) ; k++){
		if(opt == 0){
					w.re = cos(2.0*pi*k/n); 
		w.im = sin(2.0*pi*k/n);
		}
		else{
					w.re = cos(2.0*pi*k/n); 
		w.im = -sin(2.0*pi*k/n);
		}

		y[k].re = ye[k].re + (w.re * yo[k].re - w.im * yo[k].im);
		y[k].im = ye[k].im + (w.im * yo[k].re + w.re * yo[k].im);
		y[k + (n/2)].re = ye[k].re - (w.re * yo[k].re - w.im * yo[k].im);
		y[k + (n/2)].im = ye[k].im - (w.im * yo[k].re + w.re * yo[k].im);
	
	}
	return y;
}

int main(){
	int n, k, t, l;
	
	double p,q;
	scanf("%d",&t);
	struct comp* h[t];
	int op[t], on[t];
	
	for(l = 0; l<t ;l++){
		
		
		scanf("%d %d ",&opt,&n);
		op[l] = opt;
		on[l] = n;
		struct comp a[n];
		for(k = 0; k<n; k++){
			scanf("%lf %lf",&a[k].re,&a[k].im);
		}
		h[l] = recursive_FFT(a,n);
	}
		//printf("%d", n);
	for(l = 0; l<t ; l++){
		for(k = 0; k < on[l]; k++){
			if(op[l] == 0)
			p = (h[l][k].re), q = (h[l][k].im);
			else
			p = (h[l][k].re)/on[l], q = (h[l][k].im)/on[l];
			printf(" %.6f %.6f\n",p,q);
			/*if((abs(p) == 0.00)&&(abs(q) == 0.00)){
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
