%modified false position
function [ x2 ] = mod_false_position( ~ )
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
c=0;
counter=0;
for k=1:c
x2=b-(f(b)*(a-b)/(f(a)-f(b)));
if(f(a)*f(x2)<0)
    b=x2;
end    
if(f(a)*f(x2)>0)
        a=x2;
end        
if(f(a)*f(x2)==0)
    break;
end
if(abs((x2-m)*100/x2)<=d)
    break; 
end
 if (c == 2)
        c = 0;
        f(b) = f(b)/ 2;
    else
        c = c + 1;
counter=counter+1;
approxerror(counter)=(x2-m)/x2;
m=x2;
 end
double(x2)
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

