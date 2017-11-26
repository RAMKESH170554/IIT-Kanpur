#include <stdio.h>
#include <math.h>
#define Pi 3.14159265358979323846

void FFT(double ArrR[],double ArrI[],int n)
{
   int i,j;
   for(i=0;i<n;i++)
   {   double Y1=0,Y2=0;
       for(j=0;j<n;j++)
   {
       Y1=Y1+ArrR[j]*cos(2.0*Pi*i*j/n)-ArrI[j]*sin(2.0*Pi*i*j/n);
       Y2=Y2+ArrR[j]*sin(2.0*Pi*i*j/n)+ArrI[j]*cos(2.0*Pi*i*j/n);
   }
   printf("%.1lf %.1lf ",Y1,Y2);
}
}
void FFTi(double ArrR[],double ArrI[],int n)
{
    int i,j;
   for(i=0;i<n;i++)
   {   double A1=0,A2=0;
       for(j=0;j<n;j++)
   {
       A1=A1+(+ArrR[j]*cos(2.0*Pi*i*j/n)+ArrI[j]*sin(2.0*Pi*i*j/n))/n;
       A2=A2+(-ArrR[j]*sin(2.0*Pi*i*j/n)+ArrI[j]*cos(2.0*Pi*i*j/n))/n;

   }
   printf("%.1lf %.1lf ",A1,A2);
}
}
int main(){
    int n,x,i;
    scanf("%d%d",&x,&n);
    double ArrR[n],ArrI[n];
    for(i=0;i<n;i++){
        scanf("%lf",&ArrR[i]);
        scanf("%lf",&ArrI[i]);
    }
    if(x==0)
     FFT(ArrR,ArrI,n);
    else
     FFTi(ArrR,ArrI,n);
    return 0;
}
