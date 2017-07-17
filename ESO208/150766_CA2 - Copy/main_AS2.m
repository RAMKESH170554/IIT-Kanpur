%main part of program
clear
clc

prompt=sprintf('Please select one of the methods: \n(1) Gauss Elimination \n(2) Gauss Elimination with Pivoting \n(3) Gauss Elimination with Pivoting and Scaling \n(4) LU Decomposition \n(5) LU Decomposition with Pivoting \n(6) LU Decomposition (Crout Method) \n(7) Cholesky Method \n');
dlg_title='Specify method number';
num_lines=1;
y=inputdlg(prompt,dlg_title,num_lines);
z=str2double(y);
filename = input('Please enter the filename of the textfile (eg. matrix.txt): ', 's');
filedata = textread(filename, '%f');
%reshaping the input
n = filedata(1);
Ag = reshape(filedata(2:end), n+1, n);

Ag = transpose(Ag);
%calling various functions
msg='Error';
switch (z)
    case 1
        gauss(Ag, n);
    case 2
        gausspp(Ag, n);
    case 3
        gaussppsc(Ag, n);
    case 4
        ludec(Ag, n);
    case 5
        ludecpp(Ag, n);
    case 6
        ludecrout(Ag, n);
    case 7
        cholesky(Ag, n);
    otherwise
        error(msg)
end