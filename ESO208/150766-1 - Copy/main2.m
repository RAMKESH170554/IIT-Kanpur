%main2
clear
clc
prompt=sprintf('Enter 1 for muller\nEnter 2 for bairstow');
dlg_title='Specify method number';
num_lines=1;
y=inputdlg(prompt,dlg_title,num_lines);
z=str2double(y);
switch(z)
    case 1
        [xr]=muller;
    case 2
        [x1]=bairstow;
    otherwise
        printf('Error');
end        