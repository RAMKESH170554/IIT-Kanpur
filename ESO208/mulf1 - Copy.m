function out = mulf1(str,x1,x0)

syms f(x)
f(x)=sym(str);

out=eval( (f(x1)-f(x0))/(x1-x0) );

end

