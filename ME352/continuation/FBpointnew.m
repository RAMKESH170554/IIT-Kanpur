function z = FBpointnew(X)

global gp 
theta = gp;

%parameters
load fbps

D = A + L1*[cos(theta);sin(theta)];

z = [norm(X-D) - L2 ; norm(X-B) - L3];
