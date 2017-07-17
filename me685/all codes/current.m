function current(m)
format rat

R = zeros(m,m);
disp('enter sum of resistances of rightmost loop as first loop');
for i = 1:m
    R(i,i) = input('');
end   
for i = 1:m-1
    R(i,i+1) = -1;
    R(i+1,i) = -1;    
end
for i = 1:m-2
    R(i, (i+2):m) = 0;
    R((i+2):m , i) = 0;
end
R
V = zeros(m,1);
V(m) = 1;

I = zeros(m,1);

I = inv(R) * V ;

disp('currents in each loop from right is:'); 
disp('currents in E times : ');
disp(I);
EI = efficientI(m,R);

end