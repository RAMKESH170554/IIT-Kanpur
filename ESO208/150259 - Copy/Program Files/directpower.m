function directpower(A, n, iters, maxerror)

x = ones(n, 1);
l = 0;
count = 0;
for i=1:iters
    x = A*x;
    lt = max(x);
    if lt < max(abs(A)) 
        lt = -max(abs(A));
    end
    x = x / lt;
    
    count = count + 1;
    if abs((lt - l) * 100 / lt) < maxerror
        break;
    end
    l = lt;
end

out = fopen('output.txt', 'w');
fprintf(out, 'Direct Power Method\n');
printMatrix([lt], 1, 1, out, 'Eigen Value');
printMatrix(x/norm(x), n, 1, out, 'Eigen Vector');
printMatrix([count], 1, 1, out, 'Iterations');
