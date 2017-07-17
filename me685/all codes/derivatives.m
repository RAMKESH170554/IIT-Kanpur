function derivatives(a)
format long
syms x
f(x) = symfun( sin(x^3), x );
h = 0.00001;

fm = (f(x+h) - f(x-h))/ (2*h) ;
fr = (f(x+2*h) - f(x+h))/ (h) ;
fl = (f(x-h) - f(x-2*h))/ (h) ;

f1m(x) = symfun(fm , x) ;
f1r(x) = symfun(fr , x) ;
f1l(x) = symfun(fl , x) ;
f1_a = diff(f ,x,1) ;
disp('value of first derivative LHS');
disp(double(f1l(a)));
disp('value of first derivative at Center');
disp(double(f1m(a)));
disp('value of first derivative RHS');
disp(double(f1r(a)));
disp('error in first derivative at center');
disp(double(f1_a(a) - f1m(a))) ;

f2l = symfun((f1m - f1l )/ (3*h/2) , x);
f2r = symfun((f1r  - f1m)/ (3*h/2) , x) ;
f2_a = diff(f ,x,2);
disp('value of second derivative LHS');
disp(double(f2l(a)));
disp('value of second derivative RHS');
disp(double(f2r(a)));
disp('error in second derivative RHS');
disp(double(f2_a(a) - f2r(a)));


f3(x) = symfun((f2r - f2l)/(3*h/2) , x);
f3_a = diff(f ,x,3);
disp('value of third derivative');
disp(double(f3(a)));
disp('error in third derivative');
disp(double(f3_a(a)  - f3(a))); 
end
