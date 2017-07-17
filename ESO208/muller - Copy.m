function muller(str)

syms f(x)
f(x)=sym(str);

fprintf('Enter initial values :\n');
x0=input('');
x1=input('');
x2=input('');

max_it=input('Enter maximum iterations :\n');
max_erel=input('Enter maximum relative approximate error :\n');

for i=1:max_it
    
    a=mulf2(str,x2,x1,x0);
    b=( mulf1(str,x2,x1)+(x2-x1)*a );
    c=f(x2);
    
    d=sqrt( (b*b) - (4*a*c) );
    if(b<0)
        d=d*(-1);
    end
    
    x3=eval( x2 - ( 2*c/(b+d) ) );
    
    e(i)=abs(x3-x2);
    erel(i)= 100*abs(e(i)/x3);
        
    if(i>1 && erel(i)<max_erel)
        break;
    end
    
    x0=x1;
    x1=x2;
    x2=x3;
end   

out=x3;
fprintf('The root is :\n')
disp(out);

p1=figure;
p2=figure;

x=linspace(-20,20,100);
syms y;
y=f(x);
figure(p1);
plot(x,y);
xlabel('x');
ylabel('f(x)')
title('Plot of f(x) vs x');
grid;

i=linspace(1,max_it,1);
figure(p2);
plot(erel,'k-s')
xlabel('No. of Iterations');
ylabel('Relative Approximate Error');
title('Plot of Relative Approximate Error vs No. of Iterations');
grid;



end    