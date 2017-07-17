function I = efficientI(m,R)
format rat


V = zeros(m,1);
V(m) = 1;

I = zeros(m,1);
I(1) = 1/det(R) ;
for i = 1:m-1
    I(i+1) = det(R(1:i, 1:i)) / det(R) ;
end
disp('effe currents in each loop from right is:'); 
disp('currents in E times : ');
disp(I);
end