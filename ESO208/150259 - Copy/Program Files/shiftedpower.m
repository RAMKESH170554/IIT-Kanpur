function shiftedpower(A, n, iters, maxerror, shift)

x = ones(n, 1);
l = 1;
lg = 0;
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
fprintf(out, 'Shifted Power Method\n');
printMatrix([1/lt + shift], 1, 1, out, 'Eigen Value');
printMatrix(x/norm(x), n, 1, out, 'Eigen Vector');
printMatrix([count], 1, 1, out, 'Iterations');
