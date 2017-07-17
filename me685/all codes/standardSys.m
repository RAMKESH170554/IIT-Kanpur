function  standardSys()
prompt = 'Dist towards light house in bans: ';
lh = input(prompt);
prompt = 'Dist towards high peak in kos: ';
hp = input(prompt);
mat = [cos(10), -sin(5) ; -sin(10), cos(5) ];
v_units = [0.2*lh ; 15*hp];
x = mat * v_units ;
disp('North in km') ;
disp(x(1));
disp('East in km');
disp(x(2));
end
