function[L,U] = LU(A)
% perform LU decomposition of a square matrix A using the Crout method
nA=size(A);
r(1,1:nA)=A(1,1:nA);
l(1:nA,1)=A(1:nA,1)/r(1,1);
for j=2:nA
   for k=j:nA
       dum1=l(j,1:(j-1));
       dum2=r(1:(j-1),k);
       sumterm1=sum(dum1.*dum2');
       r(j,k)=A(j,k)-sumterm1;
   end 
   for m=j:nA
       dum1=l(m,1:(j-1))
       dum2=r(1:(j-1),j);
       sumterm2=sum(dum1.*dum2');
       if m==j
           l(m,j)=1;
       else    
           l(m,j) = (1/r(j,j))*(A(m,j) - sumterm2);
       end    
   end    
end   