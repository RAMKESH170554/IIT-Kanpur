from __future__ import division
import matplotlib.pyplot as plt

def func(t,y):
    sum1=10*pow(y,3) + 3*y + pow(t,2)
    print (t,sum1)
    return sum1
    

def runge(t,f,x1,z,fun,flag):
    
    h=0.01
   
    while(t<x1 and (t+h)<x1):
        z1=z
        #k1=h*func(t,f)
        #k2=h*func(t+h/2,f+k1/2)
        #k3=h*func(t+h/2,f+k2/2)
        #k4=h*func(t+h,f+k3)
        #z+=1/6*(k1+2*k2 + 2*k3 +k4)
        z+=h*func(t,f)
        f+=h*z1
        
        if flag == 1 :
            plt.plot(t,f,'bo')
            
        t+=h
        
        
    z1=z
    h=x1-t
    k1=h*func(t,f)
    k2=h*func(t+h/2,f+k1/2)
    k3=h*func(t+h/2,f+k2/2)
    k4=h*func(t+h,f+k3)
    z+=1/6*(k1+2*k2 + 2*k3 +k4)
    f+=h*z1
    if flag == 1 :
        plt.plot(t,f,'bo')
        plt.show()
    fun[0]=f
    
def shooting(t,f,f1,t1,fun,z):
    runge(t,f,t1,z,fun,0)
    e1=f1-fun[0]
    print("e1",e1)
    print("final-",fun[0])
    runge(t,f,t1,z+0.001,fun,0)
    e2=f1-fun[0]
    print("final-",fun[0])
    print("e2",e2)
    z+=(e1-e2)
    print("z-",z)
    
    runge(t,f,t1,z,fun,0)
    print("final-",fun[0])
    if abs(fun[0] - f1) >0.01 :
        return shooting(t,f,f1,t1,fun,z)
    else:
        runge(t,f,t1,z,fun,1)
    
    
    

t=0
f=0
f1=1
t1=1
fun=[]
fun.append(f)
shooting(t,f,f1,t1,fun,0.1)

    