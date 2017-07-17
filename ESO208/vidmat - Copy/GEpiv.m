function GEpiv( n, Aug )

permat=eye(n);    %permutation matrix

for i = 1:n-1   %applying Gauss elimination with pivoting(creates a upper triangular matrix)
    
    row=maxin(n-i+1,Aug(i:n,i))+i-1;   %finds maximum element in column 
    Aug([row i],:) = Aug([i row],:); %swaps rows
    permat([row i],:) = permat([i row],:);   %creating permutation matrix
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
fprintf(fid,'Gauss Elimination with pivoting\n\n');
fprintf(fid,'x\n');
for i = 1:n
    fprintf(fid,'%f\n',x(i));
end

fprintf(fid,'\nPermutation matrix\n');
for i = 1:n
    for j = 1:n
        fprintf(fid,'%f ',permat(i,j));
    end
    fprintf(fid,'\n');
end

fprintf(fid,'\nU\n');
for i = 1:n
    for j = 1:n
        fprintf(fid,'%f ',A(i,j));
    end
    fprintf(fid,'\n');
end

end
