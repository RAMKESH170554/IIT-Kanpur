function [x1,y1,z1,a,b,c] = path_traj(L1,L2,x0,y0,z0)
syms x y z
R=((L1+L2)^2)*0.75;
%eqn = x^2+y^2+z-8+100*x-2*y;
[x_sol y_sol z_sol]=solve(x^2+y^2+z^2==R,x==x0,y==y0);
[M,I]=max(z_sol);
x1=x_sol(I);
y1=y_sol(I);
z1=z_sol(I);
a = -(x1-x0);
b = -(y1-y0);
c = -(z1-z0);
end



