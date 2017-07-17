import math

def dydx(x,y):
	t = (4*x +y-1)**2
	return t

def euler(x0,y0,b):
	h = 0.1
	x = x0
	for i in range(1000000):

		y = y0 + h * dydx(x,y0)
		y0 = y
	
		if x >= b:
			break
		x = x + h
		
	return y

def mod_euler(x0,y0,b):
	h = 0.1
	x = x0
	for i in range(1000000):
		yb = y0 + h * dydx(x,y0)
		y = y0 + h * (dydx(x,y0) + dydx(x + h , yb)) * 0.5
		y0 = y
		
		if x >= b:
			break
		x = x + h

	return y

def RK4(x0,y0,b,h):
	#h = 0.001
	x = x0
	for i in range(1000000):
		if x < b:
			y1 = h * dydx(x,y0)
			y2 = h * dydx(x + h/2 ,y0 + y1 * 0.5)
			y3 = h * dydx(x + h/2 ,y0 + y2 * 0.5)
			y4 = h * dydx(x + h ,y0 + y3)
			y = (y1 + 2* y2 + 2* y3 + y4) / 6
			y0 = y + y0
			x = x + h
		else:
			break
	return y0

def adap_quad(x0,y0,b):
	eps = 0.001
	h = b - x0
	yy = 0
	yY = 9
	for j in range(10000):
		if x0 < b:
			ss = h

			while(abs(yy - yY) >= eps):
				yy = RK4(x0,y0,x0 + h, ss)
				yY = RK4(x0,y0,x0 + h, ss/2)
				ss = ss/2
				
			y0 = yY -  (yY - yy) / 15
			x0 = x0 + h
		else:
			break
			
	return y0
