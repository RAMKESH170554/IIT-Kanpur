%main
clear
clc
prompt=sprintf('Enter 1 for bisection\nEnter 2 for false position\nEnter 3 for modified false position\nEnter 4 for Newton raphson\nEnter 5 for secamt method');
dlg_title='Specify method number';
num_lines=1;
y=inputdlg(prompt,dlg_title,num_lines);
z=str2double(y);
switch (z)
    case 1
      [xr]=bisection2();
    case 2
       [x1]=false_position();
    case 3
        [x2]=mod_false_position();
    case 4
        [x3]=newton_raphson();
    case 5
        [x4]=secant();
    otherwise
    printf('errormsg');
end
