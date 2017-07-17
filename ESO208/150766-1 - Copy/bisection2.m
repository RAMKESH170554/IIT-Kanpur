%bisection
function [ xr] = bisection2(~ )
syms x
str=input('function:','s');
f=@(t)subs(str,x,t);
prompt={'Enter lower limit:','Enter upper limit:','Enter max no. of iterations:','Enter max %error:'};
dlg_title='Input data';
num_lines=1;
p=inputdlg(prompt,dlg_title,num_lines);
v=str2double(p);
a=v(1);
b=v(2);
c=v(3);
d=v(4);
x0=[a b];
m=0;
counter=0;
for k=1:c
xr=(a+b)/2;
if(f(a)*f(xr)<0)
    b=xr;
end    
if(f(a)*f(xr)>0)
        a=xr;
end        
if(f(a)*f(xr)==0)
    break;
end
if(abs((xr-m)*100/xr)<=d)
    break; 
end
counter=counter+1;
approxerror(counter)=(xr-m)/xr;
m=xr;
end
xr
x=linspace(-20,20,100);
figure(fig1)
fplot(f,[-20 20]);
title('Plot of f(x) vs. x');
xlabel('x');
ylabel('f(x)');
grid;

figure(fig2)
plot(approxerror);
title('Plot of relative approximate error vs iteration number');
xlabel('iteration number');
ylabel('Relative approx. error');
grid;


end

