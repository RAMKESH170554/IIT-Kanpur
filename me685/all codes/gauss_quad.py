import math

def f(x,o):
	t = 1 / (1 - x*x*math.sin(o) * math.sin(o))**0.5
	return t

def gaussq(a,b,x): # 3 point quadrature
	V = (b-a)*0.5
	r = (3/5)**0.5
	area = V*(5*f(x,(a+b)/2 -r*(b-a)/2)/9 + 8*f(x,(a+b)/2)/9 + 5*f(x,(a+b)/2 + r*(b-a)/2)/9 )
	return area