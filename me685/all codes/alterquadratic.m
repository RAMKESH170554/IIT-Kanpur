function [x1, x2] = alterquadratic(a,b,c)
format long G
if( a == 0)
    disp('only one root: ');
    x1 = -c/b 

    return;
end
%this function returns the roots of 
% a quadratic equation.
% It takes 3 input arguments
% which are the co-efficients of x2, x and the 
%constant term
% It returns the roots

d = disc(a,b,c); 

x1 = (-b + d)*(-b - d) ;
x1 = x1 / ((-b - d)*2*a);

x2 = (-b - d)*(-b + d) ;
x2 = x2 / ((-b + d)*2*a);

[x1a,x2a] = quadratic(a,b,c)
disp('Error in values of roots (new - actual) :');
disp(x1 - x1a);
disp(x2 - x2a);
end % end of alterquadratic

function dis = disc(a,b,c) 
%function calculates the discriminant
dis = sqrt(b^2 - 4*a*c);
end % end of sub-function