function out = mulf2(str,x2,x1,x0)

p=mulf1(str,x2,x1);
q=mulf1(str,x1,x0);

out=( (p-q)/(x2-x0) );

end

