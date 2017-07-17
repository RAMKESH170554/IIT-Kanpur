%muller
function [ xr ] = muller( ~ )
syms x
str=input('function:','s');
f=@(t)subs(str,x,t);
prompt={'Enter x(i):','Enter x(i-1):','Enter x(i-2):','Enter max no. of iterations:','Enter max %error:'};
dlg_title='Input data';
num_lines=1;
p=inputdlg(prompt,dlg_title,num_lines);
v=str2double(p);
a=v(1);
b=v(2);
c=v(3);
d=v(4);
l=v(5);
for k=1:d
  w=funct1(str,a,b,c);
    x=( funct2(str,a,b)+(a-b)*w );
    y=f(a);
    
    z=sqrt( (x*x) - (4*w*y) );
    if(x<0)
        z=z*(-1);
    end    
    xr=double( a - ( 2*y/(x+z) ) );
    
    e(k)=abs(xr-a);
    erel(k)= 100*abs(e(k)/xr);
        
    if(k>1 && erel(k)<l)
        break;
    end
    
    c=b;
    b=a;
    a=xr;
end
    xr
fig1=figure;
fig2=figure;

x=linspace(-20,20,100);
syms y;
y=f(x);
figure(fig1);
plot(x,y);
xlabel('x');
ylabel('f(x)')
title('Plot of f(x) vs x');
grid;

i=linspace(1,d,1);
figure(fig2);
plot(erel,'k-s')
xlabel('No. of Iterations');
ylabel('Relative Approximate Error');
title('Plot of Relative Approximate Error vs No. of Iterations');
grid;


end

