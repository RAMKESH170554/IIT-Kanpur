from __future__ import division
import matplotlib.pyplot as plt
from zeros import zeros

import numpy as np
from numpy.linalg import inv
        
def secondcondition(f,k,n):
    i=1
    flag=0
    while(i<n):
        if abs(f[i]-k[i]) >0.01:
            flag=1
            break 
        i+=1
    if flag==1:
        return 0
    else:
        return 1
def zeros1(D,n):
    for i in range(n):
        D.append(0)
def func(y,t):
    sum1=10*pow(y,3) +3*y + pow(t,2)
    return sum1

def initialguess(f,n,k):
    sum1=0
    for i in range(n):
        sum1+=k
        f.append(sum1)
    
def matrix(J,f,n,h):
    i=0
    j=0
    while(i<n):
        while(j<(n)):
            if i==0:
                if j==(i+1):
                    J[i][j]=1/pow(h,2)
                elif j==(i):
                    J[i][j]=-2/pow(h,2)
                else:
                    J[i][j]=0
        
            elif i==(n-1):
                if j==(i-1):
                    J[i][j]=1/pow(h,2)
                elif j==(i):
                    J[i][j]=-2/pow(h,2)
                else:
                    J[i][j]=0
                    
                
            else:
                if j==(i-1):
                    J[i][j]=1/pow(h,2)
                elif j==(i+1):
                    J[i][j]=1/pow(h,2)
                elif j==(i):
                    J[i][j]=-2/pow(h,2) 
                else:
                    J[i][j]=0
            j+=1
        i+=1
        j=0
                
def matrixD(f,n,f1,f2,h,t,D):
    i=0
    while(i<n):
        if i==0 :
            D[i]=func((f[0]+f1)/2,t-h/2) -f1/(h*h)
        elif i==(n-1):
            D[i]=func((f[n-1]+f2)/2,t-h/2) -f2/(h*h)
        else:
            D[i]=func((f[i-1]+f[i])/2,t-h/2) 
        t+=h
        i+=1
        
            
def mod(f,n):
    sum1=0
    for i in range(n):
        sum1+=pow(f[i],2)
    return sum1    
            
            
    
def solve(t,f,h,J,n,f1,f2,D):
    matrix(J,f,n,h)
    matrixD(f,n,f1,f2,h,t,D)
    m1=mod(f,n)
    k=np.matmul(inv(J),D)
    m2=mod(k,n)
    print(f)
    if abs(m2-m1)>0.1 and secondcondition(f,k,n)==0:
        f=k
        return solve(t,f,h,J,n,f1,f2,D)
    else:
        print(k)
        print(k[n-1])
        
    
    
    
    
                
       

t1=0
t2=1
f1=0
f2=1
f=[]
n=input("number of partition you are willing to make:",)
h=(t2-t1)/n
J=[]
D=[]
k=(f2-f1)/n
initialguess(f,n-1,k)
zeros(J,n-1,n-1)
zeros1(D,n-1) 
np_D=np.array(D)
np_J=np.array(J)
np_f=np.array(f)
solve(t1+h,np_f,h,np_J,n-1,f1,f2,np_D)

