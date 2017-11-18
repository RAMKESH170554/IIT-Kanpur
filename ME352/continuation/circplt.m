function z=circplt(G)

global gp

t=gp;
x = G(1);
y = G(2);
z=[x + y + t*t - 2 ; sin(y*x)-t ]; 