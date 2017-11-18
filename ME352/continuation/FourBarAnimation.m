function FourBarAnimation(x,dth,N)

if nargin == 1
    dth = 0.02;
end
if nargin < 3
    N = 100;
end
A = x(1,:)';
B = x(2,:)';
C = x(3,:)';
D = x(4,:)';

global gp globalsolution

L1 = norm(A-D);
L2 = norm(D-C);
L3 = norm(B-C);

save fbps L1 L2 A B L3

AD = D - A;
theta = atan2(AD(2),AD(1));
globalsolution = [C;theta];
gp = theta + dth ;
newton('FBpointnew',C);

globalsolution = [globalsolution,[ans;gp]];

run_continuation('FBpointnew',N);

