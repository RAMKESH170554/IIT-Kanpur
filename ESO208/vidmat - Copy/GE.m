function GE( n, Aug )

for i = 1:n-1   %applying Gauss elimination(creates a upper triangular matrix)
    for j = i+1:n
        Aug(j,:) = Aug(j,:) - Aug(i,:)*Aug(j,i)/Aug(i,i) ;
    end
end

A=Aug(:,1:end-1);  %coefficient matrix after GE
b=Aug(:,end);      %constant vector after GE

x=zeros(n,1);      %solution vector
x(n)=b(n)/A(n,n);  %calculation x(n)

for i = n-1:-1:1   %calculating x(i)s by backward substitution
    sum=b(i);
    for j = n:-1:i+1
        sum=sum-A(i,j)*x(j);
    end
    x(i)=sum/A(i,i);
end

%writing output to file
fid = fopen( 'output.txt', 'wt' );
fprintf(fid,'Gauss Elimination\n\n');
fprintf(fid,'x\n');
for i = 1:n
    fprintf(fid,'%f\n',x(i));
end
fprintf(fid,'\nU\n');
for i = 1:n
    for j = 1:n
        fprintf(fid,'%f ',A(i,j));
    end
    fprintf(fid,'\n');
end

end

