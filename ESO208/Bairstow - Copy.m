function Bairstow(expr)

syms x;         
P = expr;
r = str2double(input ('Coefficient of x = ', 's')); %coefficient of x
s = str2double(input ('Constant term = ', 's')); %constant term
n = str2num(input ('Number of iterations = ', 's'));

u = -r;
v = -s;

for i = 1:n
  fx = x^2 + u*x + v;
  [R, rem] = quorem (P, fx, x);
  [U, rem2] = quorem(R, fx, x);
  M = sym2poly(rem);
  if (length(M)==2)
    c = M(1); d = M(2);
  end
  if (length(M)==1)
    c = M(1); d = 0;
  end
  if (isempty(M))
    c = 0; d = 0;
  end
  M = sym2poly(rem2);
  if (length(M)==2)
    g = M(1); h = M(2);
  end
  if (length(M)==1)
    g = M(1); h = 0;
  end
  if (isempty(M))
    g = 0; h = 0;
  end
  if (c==0 && d==0)
    break;
  end
  u = u - (g*d-c*h)/(v*g*g-h*(h-u*g));
  v = v - (-g*v*c + (g*u-h)*d)/(v*g*g-h*(h-u*g));
end

r1 = (-u + (u^2 - 4*v)^0.5)/2;
r2 = (-u - (u^2 - 4*v)^0.5)/2;

fprintf('\n Root 1: \n');
disp(r1); %value obtained by algorithm
fprintf('\n Root 2: \n');
disp(r2); %value obtained by algorithm

fplot(expr, [-10,+10]); %plot f(x) vs x over interval [xl,xu]
  