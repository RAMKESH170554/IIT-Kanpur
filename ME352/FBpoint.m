function z=FBpoint(X,p)
global theta
% parameters
Lbase=5.9; L1=3; L2=4; L3=4.5;
A=[0;0];
B=[Lbase;0];
D=L1*[cosd(theta);sind(theta)];
z=[norm(X-D)-L2; norm(X-B)-L3];
% so far, the same as before; new stuff follows
if nargin==2
C=X;
figure(1)
clf
y=[A,B]; plot(y(1,:),y(2,:),'m','linewidth',3)
axis('image') % important
axis([-1,1.3,-1,1.4]) % can be adjusted
hold on
y=[B,C]; plot(y(1,:),y(2,:),'k','linewidth',3)
y=[C,D]; plot(y(1,:),y(2,:),'r','linewidth',3)
y=[D,A]; plot(y(1,:),y(2,:),'b','linewidth',3)
hold off
end