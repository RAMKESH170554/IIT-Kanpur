function Shift(A,n,maxit,relerr,shift)
I=eye(n);
C=A-(shift)*I;
B=inv(C);
Y=ones(n,1);
count=0;
c=0;
for k=1:maxit
Y=B*Y;
a=max(abs(Y));
b=max(Y);
if(a==b)
    M=a;
else
    M=min(Y);
end
Y=rdivide(Y,M);
count=count+1;
if(abs(M-c)*100/M<relerr)
    break;
end
c=M;
end
e=1/M;
out=fopen('Shift.txt','w');
fprintf(out,'Shifted power method\n');
fprintf(out,'Eigen value->%f\n',e+shift);
fprintf(out,'Iterations->%f\n',count);
dlmwrite('Shift.txt', Y/norm(Y),'-append');


end


