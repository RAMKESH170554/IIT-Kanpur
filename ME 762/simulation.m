function simulation(th1,th2,th3,th4,a,b,c,x0,y0,z0)

steps = 0.5;
tf = 3;
t0 = 0;
n = tf/steps;
syms t
%assumung initial theta to be .01 times of all thetas
j=1;
x1 = th1/n;
x2 = th2/n;
x3 = th3/n;
x4 = th4/n;
%     x1 = symfun(th1*0.01 + t*t*3*0.99*th1/(tf*tf) - 2*0.99*t*t*t*th1/(tf*tf),t);
%     x2 = symfun(th2*0.01 + t*t*3*0.99*th2/(tf*tf) - 2*0.99*t*t*t*th2/(tf*tf),t);
%     x3 = symfun(th3*0.01 + t*t*3*0.99*th3/(tf*tf) - 2*0.99*t*t*t*th3/(tf*tf),t);
%     x4 = symfun(th4*0.01 + t*t*3*0.99*th4/(tf*tf) - 2*0.99*t*t*t*th4/(tf*tf),t);

while(j<=n)
%     dh_param = [0 0 0 x1(steps*j);0 pi/2 0 x2(steps*j);1 0 0 x3(steps*j);1 0 0 x4(steps*j);0.1 0 0 0];
  dh_param = [0 0 0 x1*j;0 pi/2 0 x2*j;1 0 0 x3*j;1 0 0 x4*j;0.1 0 0 0];
    M1 = FwdKin(dh_param,1);
    [a1, b1, c1]=deal(M1(1,4),M1(2,4),M1(3,4));
    M2 = FwdKin(dh_param,2);
    M3 = FwdKin(dh_param,3);
    M4 = FwdKin(dh_param,4);
    M5 = FwdKin(dh_param,5);
    M2 = M1*M2;
    [a2, b2, c2]=deal(M2(1,4),M2(2,4),M2(3,4));
    M3 = M2*M3;
    [a3, b3, c3]=deal(M3(1,4),M3(2,4),M3(3,4));
    M4 = M3*M4;
    [a4, b4, c4]=deal(M4(1,4),M4(2,4),M4(3,4));
    M5 = M4*M5;
    [a5, b5, c5]=deal(M5(1,4),M5(2,4),M5(3,4));
    X = j*a/(n+1);
    Y = j*b/(n+1);
    Z = j*c/(n+1);
    i = 1;
    while(i<=6)
        x_p = x0-i*X/6;
        y_p = y0-i*Y/6;
        z_p = z0-i*Z/6;
        i=i+1;
        plot3(x_p,y_p,z_p,'*');hold on;grid on;
    end
    plot3([a1 a2],[b1 b2],[c1 c2],'ro-');hold on;grid on;
    plot3([a2 a3],[b2 b3],[c2 c3],'ro-');hold on;grid on;
    plot3([a3 a4],[b3 b4],[c3 c4],'ro-');hold on;grid on;
    plot3([a4 a5],[b4 b5],[c4 c5],'ro-');hold on;grid on;
    xlim([-2.5 2.5])
    ylim([-2.5 2.5])
    zlim([-2.5 2.5])
    xlabel('x') 
    ylabel('y')
    zlabel('z')
    hold off;
    
 saveas(figure,sprintf('FIG%d.png',j));
    Movies(j)=getframe;
    j=j+1;
end
double(M4(1,4));
end