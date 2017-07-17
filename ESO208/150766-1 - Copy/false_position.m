%flase position
function [ x1 ] = false_position( ~ )
syms x
str=input('function:','s');
f=@(t)subs(str,x,t);
prompt={'Enter xl:','Enter xu:','Enter max no. of iterations:','Enter max %error:'};
dlg_title='input data';
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
x1=b-(f(b)*(a-b)/(f(a)-f(b)));
if(f(a)*f(x1)<0)
    b=x1;
end    
if(f(a)*f(x1)>0)
        a=x1;
end        
if(f(a)*f(x1)==0)
    break;
end
if(abs((x1-m)*100/x1)<=d)
    break; 
end
counter=counter+1;
approxerror(counter)=(x1-m)/x1;
m=x1;
end
double(x1)
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

