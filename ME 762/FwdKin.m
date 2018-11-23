function T = FwdKin(dh_param,i)

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

end
