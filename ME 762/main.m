function main
syms x2 x3 x4
format long
x0 =0.5;
y0= -0.5;
z0 = 2;
[x y z a b c]= path_traj(1,1,x0,y0,z0);
x1 = asin(y/(x^2+y^2)^0.5);
dh_param=([0 0 0 x1;0 pi/2 0 x2;1 0 0 x3;1 0 0 x4]);
R_inv = [cos(x1),sin(x1),0;-sin(x1),cos(x1),0;0,0,1];
dir = R_inv*[a;b;c];
slope = atan(dir(3)/dir(1));
i=1;
while(i<=4)
    T(1,1)=cos(dh_param(i,4));
    T(1,2)=-sin(dh_param(i,4));
    T(1,3)=0;
    T(1,4)=dh_param(i,1);
    T(2,1)=sin(dh_param(i,4))*cos(dh_param(i,2));
    T(2,2)=cos(dh_param(i,4))*cos(dh_param(i,2));
    T(2,3)=-sin(dh_param(i,2));
    T(2,4)=-sin(dh_param(i,2))*dh_param(i,3);
    T(3,1)=sin(dh_param(i,4))*sin(dh_param(i,2));
    T(3,2)=cos(dh_param(i,4))*sin(dh_param(i,2));
    T(3,3)=cos(dh_param(i,2));
    T(3,4)=cos(dh_param(i,2))*dh_param(i,3);
    T(4,1)=0;
    T(4,2)=0;
    T(4,3)=0;
    T(4,4)=1;
    if(i==1)
        M=T;
    else
        M=M*T;
    end
    i=i+1;
end

%slope = pi/2;

[x2, x3]= solve([M(2,4)==y, M(3,4)==z]);
[x2,i] = min(x2);
double(x2);
x3 = double(x3(i));
x4 = double(solve(x2+x3+x4 == slope));
simulation(x1,x2,x3,x4,a,b,c,x0,y0,z0);

end

