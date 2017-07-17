function Direct(A,n,maxit,relerr)
Y=ones(n,1);
count=0;
c=0;
for k=1:maxit
Y=A*Y;
a=max(abs(Y));
b=max(Y);
if(a==b)
    M=a;
else
    M=min(Y);
end
Y=rdivide(Y,M);
count=count+1;
if((M-c)*100/M<relerr)
    break;
end
c=M;
end
out=fopen('Direct.txt','w');
fprintf(out,'Direct power method\n');
fprintf(out,'Eigen value->%f\n',M);
fprintf(out,'Iterations->%f\n',count);
fprintf(out,'Eigenvector\n');
dlmwrite('Direct.txt', Y/norm(Y),'-append');

end

