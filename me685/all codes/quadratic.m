function [x1, x2] = quadratic(a,b,c)
format long G
if( a == 0)
    disp('only one root: ');
     -c/b ;
    return;
end
%this function returns the roots of 
% a quadratic equation.
% It takes 3 input arguments
% which are the co-efficients of x2, x and the 
%constant term
% It returns the roots

d = sqrt(b^2 - 4*a*c);

x1 = (-b + d) / (2*a);

x2 = (-b - d) / (2*a);


end % end of quadratic


