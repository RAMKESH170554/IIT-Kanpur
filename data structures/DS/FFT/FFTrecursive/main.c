#include <stdio.h>
#include <complex.h>
#define Pi 3.14159265358979323846
int x;
struct A
{
    double r;
    double i;
};
struct A* FFT(struct A a[],int n)
{    if(n==1)
     return a;

     struct A a0[n/2],a1[n/2],*b0,*b1;
     struct A* y=(struct A*)malloc(n*sizeof(struct A));
    int i;
    for(i=0;i<n/2;i++)
    {
       a0[i].r=a[2*i].r;
       a0[i].i=a[2*i].i;
       a1[i].r=a[2*i+1].r;
       a1[i].i=a[2*i+1].i;
    }
    b0=FFT(a0,n/2);
    b1=FFT(a1,n/2);

    double complex w[n/2];
    double z= (2.0*Pi)/n;
    if(x==0)
      for(i=0;i<n/2;i++)
      w[i]=cexp(z*I*i);
    else if(x==1)
      for(i=0;i<n/2;i++)
      w[i]=cexp(-z*I*i);

    for(i=0;i<n/2;i++)
    {
           y[i].r=b0[i].r+creal(w[i])*b1[i].r-cimag(w[i])*b1[i].i;
           y[i].i=b0[i].i+creal(w[i])*b1[i].i+cimag(w[i])*b1[i].r;
       y[i+n/2].r=b0[i].r-creal(w[i])*b1[i].r+cimag(w[i])*b1[i].i;
       y[i+n/2].i=b0[i].i-creal(w[i])*b1[i].i-cimag(w[i])*b1[i].r;
    }
    return y;
}
int main()
{
    int i,n;
    scanf("%d%d",&x,&n);
    struct A Arr[n],*Y;

    for(i=0;i<n;i++)
    scanf("%lf%lf",&Arr[i].r,&Arr[i].i);
    Y=FFT(Arr,n);

    printf("%d ",n);
    if(x==0)
    for(i=0;i<n;i++)
     {   int p=Y[i].r,q=Y[i].i;
         if(p==0)
            printf("%d ",p);
         else
            printf("%.1lf ",Y[i].r);
         if(q==0)  printf("%d ",q);
         else
            printf("%.1lf ",Y[i].i);
     }
    else if(x==1)
    for(i=0;i<n;i++)
      {   int p=Y[i].r,q=Y[i].i;
         if(p==0)
            printf("%d ",p);
         else
            printf("%.1lf ",(Y[i].r)/n);
         if(q==0)  printf("%d ",q);
         else
            printf("%.1lf ",(Y[i].i)/n);
     }
return 0;
}
