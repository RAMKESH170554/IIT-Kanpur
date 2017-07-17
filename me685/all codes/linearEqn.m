function linearEqn(m,n)
format long G
v = 10e-6 ;
A = zeros(m,n);
disp('enter numbers row wise in A');
for i = 1:m
    for j = 1:n
        A(i,j) = input('');
    end
end
disp('enter for values in b');
b = zeros(m,1);
for i = 1:m
    b(i,1) = input('');
end
I = eye(n);
X = zeros(n,1);
disp('Approx solution : ');
X = (inv( A' * A + v * I)) * A' * b;
 disp(X);
end
