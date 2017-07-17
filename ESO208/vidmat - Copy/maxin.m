function t = maxin( n, vect )   %finds the maximum element of the column for pivoting

t=1;
max=vect(1);
for i = 1:n
    if max<vect(i)
        max=vect(i);
        t=i;
    end
end

end

