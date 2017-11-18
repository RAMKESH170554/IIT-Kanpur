function M = FBmovie
global theta
% use initial points already found
Xguess=[0.824894064717124; 0.491899414279410];
t=linspace(1.4,1.4+2*pi,100); t=t(1:99);
for k=1:99
theta=t(k);
Xguess=newton('FBpoint',Xguess);
FBpoint(Xguess,1);
figure(1)
M(k)=getframe;
end