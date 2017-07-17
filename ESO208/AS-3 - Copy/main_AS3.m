%main part of program
clear
clc

prompt=sprintf('Please select one of the methods: \n(1) Direct power method \n(2) Inverse power method \n(3) Shifted power method \n(4) QR method\n');
dlg_title='Specify method number';
num_lines=1;
y=inputdlg(prompt,dlg_title,num_lines);
z=str2double(y);
filename = input('Please enter the filename of the textfile (eg. matrix.txt): ', 's');
filedata = textread(filename, '%f');
n = filedata(1);
A=reshape(filedata(2:end-3),n,n);
A=transpose(A);
maxit=filedata(end-2);
relerr=filedata(end-1);
shift=filedata(end);
msg='Error';
switch(z)
    case 1
        Direct(A,n,maxit,relerr);
    case 2
        Inverse(A,n,maxit,relerr);
    case 3
        Shift(A,n,maxit,relerr,shift);
    case 4
        QR(A,n,maxit,relerr);
    otherwise
        error(msg);
end       
