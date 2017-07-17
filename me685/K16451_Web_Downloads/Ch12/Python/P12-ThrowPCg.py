# Oblique throw of an object with drag using the Euler PC method
from math import *
from ode import *
from graphlib import *

g = 9.81e0                                       # gravitational acceleration

def Func(t, y, f):                 # RHSs of 1st order ODEs for oblique throw
   f[1] = y[3]                     # y[1] = x, y[2] = y, y[3] = vx, y[4] = vy
   f[2] = y[4]
   f[3] = -k/m * y[3]*fabs(y[3])
   f[4] = -k/m * y[4]*fabs(y[4]) - g

# main

m = 7.26e0                                                   # mass of hammer
R = 0.06e0                                                 # radius of hammer
x0 = 0e0; y0 = 3e0                                         # initial position
v0 = 29e0                                                  # initial velocity
phi = 45e0 * pi/180e0                                           # throw angle
vx0 = v0 *cos(phi); vy0 = v0*sin(phi)                      # initial velocity
rho = 1.2                                                    # density of air
Cd = 0.5e0                                                 # drag coefficient
k = 0.5e0*rho*(pi*R*R)*Cd                              # velocity coefficient
tmax = 20e0                                                       # time span
ht = 0.001e0                                                 # time step size

n = 4                                              # number of 1st order ODEs
nt = int(tmax/ht + 0.5) + 1                            # number of time steps
y = [0]*(n+1)                                           # solution components
tt = [0]*(nt+1); xt = [0]*(nt+1); yt = [0]*(nt+1)           # plotting arrays

t = 0e0; it = 1
y[1] = x0; y[3] = vx0                                        # initial values
y[2] = y0; y[4] = vy0
tt[1] = t; xt[1] = y[1]; yt[1] = y[2]                    # store for plotting

while (t+ht <= tmax):                                      # propagation loop
   EulerPC(t,ht,y,n,Func)
   t += ht; it += 1

   tt[it] = t; xt[it] = y[1]; yt[it] = y[2]              # store for plotting
   if (y[2] < 0.e0): break                   # stop if object hits the ground

print("xmax = {0:5.2f}".format(y[1]))

GraphInit(1200,600)
Plot(tt,yt,it,"blue",1,0.10,0.45,0.15,0.85,"t","y","Altitude")
Plot(xt,yt,it,"blue",1,0.60,0.95,0.15,0.85,"x","y","Trajectory")
MainLoop()
