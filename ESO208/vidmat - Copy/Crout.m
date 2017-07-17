function Crout( n, Aug )

L=zeros(n);   %L matrix
A=Aug(:,1:end-1);  %coefficient matrix 
b=Aug(:,end);   %constant vector 

for i = 1:n-1   %applying Gauss elimination(creates a U matrix)and creating L matrix
    l=A(i,i);
    A(i,:)=A(i,:)/l;
    L(i,i)=l;
    for j = i+1:n
        l=A(j,i)/A(i,i);
        A(j,:) = A(j,:) - A(i,:)*l ;
        L(j,i)=l;
    end
end

L(n,n)=A(n,n);
A(n,:)=A(n,:)/A(n,n);

y=zeros(n,1);      %solution vector for Ly=b
y(1)=b(1)/L(1,1);  %calculation of y(1)

for i = 2:n   %calculating y(i)s by forward substitution
    sum=b(i);
    for j = 1:i-1
        sum=sum-L(i,j)*y(j);
    end
    y(i)=sum/L(i,i);
end

x=zeros(n,1);      %solution vector for Ux=y
x(n)=y(n)/A(n,n);  %calculation x(n)

for i = n-1:-1:1   %calculating x(i)s by backward substitution
    sum=y(i);
    for j = n:-1:i+1
        sum=sum-A(i,j)*x(j);
    end
    x(i)=sum/A(i,i);
end

%writing output to file
fid = fopen( 'output.txt', 'wt' );
fprintf(fid,'LU decomposition using Crout method\n\n');
fprintf(fid,'x\n');
for i = 1:n
    fprintf(fid,'%f\n',x(i));
end

fprintf(fid,'\nL\n');
for i = 1:n
    for j = 1:n
        fprintf(fid,'%f ',L(i,j));
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