function [x] = back_forward_substitute(A,back_or_forward)
% perform forward or back substitution depending on whether 
% back_or_forward is 1 or 2. The matrix A is the augmented 
% matrix [A|b] with size nA X nA+1.
nA=size(A,1);
x(1:nA,1)=0;
for ij=1:nA
    if back_or_forward == 1
    ii=nA-ij+1;
    end
    b(ii,1)=A(ii,nA+1);
    
    if ij == 1
        x(ii)=b(ii,1)/A(ii,ii);
    else  
        dum1=A(ii,(ii+1):nA);
        dum2=x(ii+1:nA,1);
        dum3=sum(dum1.*dum2');
        x(ii,1) = (1/A(ii,ii))*(b(ii)-dum3);
    end    
end    