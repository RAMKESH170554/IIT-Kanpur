function QR(A, n, maxit, relerr)

x0 = zeros(n, 1);
count = 0;

for i=1:maxit
    Q = A;
    for x=1:n
        sum = 0;
        v = Q(:, x);
        for y=1:x-1
            p = Q(:, y)' * v;
            sum = sum + Q(:, y)*p(1);
        end
        v = v-sum;
        v = v / norm(v);
        Q(:, x) = v;
    end
    A = Q'*A*Q;
    x = diag(A);
    
    count = count + 1;
    if (max((x - x0)*100 ./ x) < relerr)
        break
    end
    x0 = x;
end

out = fopen('QR.txt', 'w');
fprintf(out, 'QR Method\n');
fprintf(out,'Iterations->%f\n',count);
fprintf(out,'Eigen values\n');
dlmwrite('QR.txt', x,'-append');