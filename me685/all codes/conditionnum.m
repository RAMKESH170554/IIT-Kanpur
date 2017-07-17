function conditionnum()
format long
disp('enter inputs x, y :');
x = input('');
y = input('');
syms g b
f(g,b) = symfun(exp(g) - log(b) , [g b]);
disp('size of input :');
disp(abs(x) + abs(y));
disp('size of output :');
disp(abs(f(x,y)));
X = (abs(x) + abs(y));
Y = abs(f(x,y));
h_x = 0.01;
h_y = 0.01;
X_del = abs(h_x) + abs(h_y);
Y_del = abs( f(x,y) - f(x + h_x , y + h_y ));
disp('change in f:');
disp(double(Y_del));
if (Y == 0)
    disp('condition number is inf');
    return;
end
cond = double( (Y_del/Y)/(X_del/X));
disp('condition number:')
disp(cond);
end
