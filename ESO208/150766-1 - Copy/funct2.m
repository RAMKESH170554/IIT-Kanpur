function  out = funct2( str,b,c )
syms f(x)
f(x)=sym(str);
out=double( (f(b)-f(c))/(b-c) );


end

