function x=newton(fun,x)
format long
n=length(x);
epsil=(1e-6*max(1,norm(x)));
pert=eye(n)*epsil;
iter=0;
nmax=60;
ee=feval(fun,x);
while (norm(ee)*max(1,norm(x))>1e-10)*(iter<nmax)
iter=iter+1;
for k=1:n
D(:,k)=(feval(fun,x+pert(:,k))-ee)/epsil;
end
x=x-(D\ee);
if nargin == 3
disp(x)
end
ee=feval(fun,x);
end
if (iter == nmax)+(abs(x)==inf)
x=inf;
disp('did not converge')
end