function Inverse(A,n,maxit,relerr)
Y=ones(n,1);
count=0;
c=0;
for k=1:maxit
Y=A\Y;
a=max(abs(Y));
b=max(Y);
if(a==b)
    M=a;
else
    M=min(Y);
end
Y=rdivide(Y,M);
count=count+1;
e = 1/M;
if((e-c)*100/e<relerr)
    break;
end
c=e;
end
out=fopen('Inverse.txt','w');
fprintf(out,'Inverse power method\n');
fprintf(out,'Eigen value->%f\n',e);
fprintf(out,'Iterations->%f\n',count);
dlmwrite('Inverse.txt', Y/norm(Y),'-append');


end

