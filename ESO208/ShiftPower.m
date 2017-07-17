function ShiftPower( A , n, s, maxit, maxerel)
x=ones(n,1);
Mprev=1;
B=inv(A-s*eye(n));

for t = 1:maxit
    x=B*x;
    [maxval, maxindex]=max(abs(x));         %max element of x(absolute value)
    M=x(maxindex);
    x=x/abs(M);                             %dividing the vector by the maximum element
    
    erel=100*abs((M-Mprev)/M);              %calculating relative error
    if(erel<maxerel)
        break;
    end
    Mprev=M;
end

M=1/M;
M=M+s;                                      %eigan value
x=x/norm(x);                                %normalizing the eigan vector

%writing output to file
fid = fopen( 'ShiftPoweroutput.txt', 'wt' );
fprintf(fid,'Shifted Power Method\n\n');
fprintf(fid,'Eiganvalue\n');
fprintf(fid,'%.4f\n',M);
fprintf(fid,'\nEigenvector\n');
for i = 1:n
    fprintf(fid,'%.4f\n',x(i));
end
fprintf(fid,'\nIterations\n');
fprintf(fid,'%d',t);

end


