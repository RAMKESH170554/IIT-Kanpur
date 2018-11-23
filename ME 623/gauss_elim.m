function [x] = gauss_elim(A,b)
% Function that solves the linear system Ax=b using the Gaussian
% elimination algorithm with row pivoting. A should be a nXn square matrix
% and b a nX1 vector. The solution is returned in a nX1 vector x. All
% steps in the solution are demonstrated in a figure window if n is 
% less than 10.
nA=size(A,2);
nb=size(b,1);
if nA ~= nb
    disp('Dimension mismatch between A and b');
    return;
end
if size(A,1) ~= size(A,2)
    disp('A is not square');
    return;
end
A0=[A b];
% elimination step
for ii=1:nA-1 %loop over row
%find pivot
dum1=abs(A0(ii:nA,ii));
[maxval,i]=max(dum1);
ipivot=ii+i-1;
% form permutation matrix
P=diag(ones(nA,1));
P(ii,ii)=0; P(ii,ipivot)=1;
P(ipivot,ipivot)=0; P(ipivot,ii)=1;
%permute
A0=P*A0;
Apiv=A0;
% elimination matrix
G=diag(ones(nA,1));
dum2=-A0((ii+1):nA,ii)/A0(ii,ii);
G((ii+1):nA,ii)=dum2;
% elimination
Aelim=G*Apiv;
A0=Aelim;
end
% back substitution
x=back_forward_substitute(A0,1);
    
 



