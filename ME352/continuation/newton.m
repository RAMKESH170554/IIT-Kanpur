function x=newton(fname,x)
format long
f0=feval(fname,x);
n=length(x);
count=0;

while (norm(f0) > 1e-10*max(1,norm(x)))*(count<60)
    epsil=1e-5;
    E=eye(n)*epsil;
    
    D=E; % initialization; will be overwritten
    for k=1:n
        temp=feval(fname,x+E(:,k));
        D(:,k)=(temp-f0)/epsil ;
    end
    
    x=x-D\f0 ;
    f0=feval(fname,x) ;
    count=count+1;
end

if count >=60, x=inf; end
