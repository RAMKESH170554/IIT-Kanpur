function cams_design
theta = linspace(0,2*pi,30000);
for i=1:30000
    t(i) = func(theta(i)) + d2dy(theta(i));
end
plot(theta,t);
min(t)
end

function y = func(x)
y = ((170*(sin(x/2))^6)/(1+6*(sin(x/2))^6));
end

function p = d2dy(x)
dx = 0.001;
p = (func(x+dx) - 2*func(x) + func(x-dx))/(dx*dx) ;
end

