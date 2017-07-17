import math
import random

def f(x,y):
	t = math.exp(-x*y)
	return t

def domain(x,y):
	p = (x >= 0) & (x <= (1 - y*y)**0.5)
	return p

def dinteg(a,b,c,d):# form y : a to b x: c to d  // f(x,y)dx.dy
	t = [-1,0,1]
	w = [16/9, 4/9 , 1/9]
	x = [0,0,0]
	y = [0,0,0]
	for i in range(3):
		y[i] = (b+a)*0.5 + 0.5*(b-a) * t[i]
		x[i] = (c+d)*0.5 + 0.5*(d-c) * t[i]
	area = w[0] * f(x[1],y[1])
	#for i in range(4):
	area = area + w[1] * (f(x[0],y[1]) + f(x[2],y[1]) + f(x[1],y[0]) + f(x[1],y[2]))
	area = area + w[2] * (f(x[0],y[0]) + f(x[0],y[2]) + f(x[2],y[0]) + f(x[2],y[2]))
	area = area * 0.25 * (b-a)*(d-c)
	return area


def monte_carlo(a,b,c,d):
	I = 0
	V = (b-a)*(d-c)
	k = 100
	for i in range(100):
		tu = 0
		Ipre = I
		for j in range(k):
			x = random.uniform(a,b)
			y = random.uniform(c,d)
			if domain(x,y) == True:
				tu = f(x,y) + tu
		I = tu * V / k
		k = k * 2
		if abs(I - Ipre) < 0.0001:
			return I
		else:
			continue
	return