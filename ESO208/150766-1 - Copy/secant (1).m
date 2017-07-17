%secant
function [ x4 ] = secant( ~ )
syms x
str=input('function:','s');
f=@(t)subs(str,x,t);
prompt={'Enter x(-1):', 'Enter x(0):','Enter max no. of iterations:','Enter max %error:'};
dlg_title='Input data';
num_lines=1;
p=inputdlg(prompt,dlg_title,num_lines);
v=str2double(p);
a=v(1);
b=v(2);
c=v(3);
d=v(4);
m=0;
counter=0;
for k=1:c
x4=b-f(b)*(a-b)/(f(a)-f(b));
if((x4-b)*100/x4<=d)
break;
end
b=x4;
counter=counter+1;
approxerror(counter)=(x4-m)/x4;
m=x4;
end
double(x4)
fig1=figure;
fig2=figure;
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

