clc;
t=linspace(0,2,9);
b=input("enter the value of f in form of 1X9 column vector ");
function e=error(x,b,t)
  for c=1:9
    e(c)=x(1)+x(2)*t(c)+x(3)*(t(c))^2+(x(4))*exp(x(5)*t(c))-b(c);
  end
end
function J=Jac(x,b,t)
  for c=1:9
      J(c,1)=1;
      J(c,2)=t(c);
      J(c,3)=(t(c))^2;
      J(c,4)=exp(x(5)*t(c));
      J(c,5)=(t(c)*x(4))*exp(x(5)*t(c));
   end
end
x=input("enter the initial point x in a 5X1  column vector");
lam=0.1;
for c=1:1000
  J=Jac(x,b,t);
  H=J'*J+lam.*diag(diag(J'*J));
  delx=inv(H)*(J'*(error(x,b,t)'));
  c;
  x=x-(delx);
  norm(error(x,b,t));
end
x

    
  