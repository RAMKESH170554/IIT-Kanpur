%newton raphson
function [ x3] = newton_raphson( ~ )
syms x
str=input('function:','s');
f=@(t)subs(str,x,t);
f1(x)=f(x);
prompt={'Enter x0:','Enter max no. of iterations:','Enter max %error:'};
dlg_title='Input data';
num_lines=1;
h=inputdlg(prompt,dlg_title,num_lines);
g=str2double(h);
x0=g(1);
a=g(2);
b=g(3);
f3(x)=diff(f1);
counter=0;
m=0;
for k=1:a
x3=x0-f(x0)/f3(x0);
if((x3-x0)*100/x3<=b)
break;
end
x0=x3;
counter=counter+1;
approxerror(counter)=(x3-m)/x3;
m=x3;
end
double(x3)
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

