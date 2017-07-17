import math

def dydx(x,y):
	t = x*x*y
	return t

def multistep(x0,y0,y1,y2,b): # initial values need to given
	h = 0.0001
	#y1 = y0 + (h/12)*(23* dydx(x0,y0))
	#y1 = y0 + (h/12)*(5 * dydx(x0 + h, y1))
	#y2 = y1 + (h/12)*(23* dydx(x0 + h, y1) - 16*dydx(x0, y0))
	#y2 = y1 + (h/12)*(5 * dydx(x0 + 2*h, y2) + 8*dydx(x0 + h, y1))
	for i in range(1000000):
		if x0 <= b:
			y3 = y2 + (h/12)*(23 * dydx(x0 + 2*h, y2) - 16*dydx(x0 + h, y1) + 5*dydx(x0,y0))
			y3 = y2 + (h/12)*(5 * dydx(x0 + 3*h, y3) + 8*dydx(x0 + 2*h, y2) - dydx(x0 + h,y1))
			y0 = y1
			y1 = y2
			y2 = y3
			x0 = x0 + h
		else:
			return y3
	return