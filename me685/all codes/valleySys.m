function  valleySys()
prompt = 'Dist in north in km: ';
north = input(prompt);
prompt = 'Dist in east in km: ';
east = input(prompt);
mat = [cos(10), -sin(5) ; -sin(10), cos(5) ];
s_units = [north ; east];
v = inv(mat) * s_units ;
disp('dist towards Light house in bans') ;
disp(v(1)/.2);
disp('dist towards High valley in kos');
disp(v(2)/15);
end
