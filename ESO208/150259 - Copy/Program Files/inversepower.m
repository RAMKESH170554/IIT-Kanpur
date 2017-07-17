function inversepower(A, n, iters, maxerror)

x = ones(n, 1);
l = 0;
count = 0;
for i=1:iters
    x = A*x;
    lt = max(x);
    if lt < max(abs(A)) 
        lt = -max(abs(A));
    end
    ev = 1 / lt;
    x = x / lt;
    
    count = count + 1;
    if abs((ev - l) * 100 / ev) < maxerror
        break;
    end
    l = ev;
end

out = fopen('output.txt', 'w');
fprintf(out, 'Inverse Power Method\n');
printMatrix([ev], 1, 1, out, 'Eigen Value');
printMatrix(x/norm(x), n, 1, out, 'Eigen Vector');
printMatrix([count], 1, 1, out, 'Iterations');
