import math



def newton(x):
	for i in range(1000000):
		if abs(f(x)) > 0.0001:
			x = x - f(x)/f_der(x)
		else:
			print ('number of iterations',i)
			print ('root',x)
			break
	return

def falsePos(x0,x1):
	x2 = 0
	for i in range(1000000):
		if abs(f(x2)) > 0.0001:
			x2 = x0 - f(x0) * (x1 - x0)/(f(x1) - f(x0))
			x0 = x1
			x1 = x2
		else:
			print ('number of iterations',i)
			print ('root',x2)
			break
	return

def f(x):
	t = 4*x*x*x - 42*x*x+120*x-70 #30 * math.sin(x) + pow(x,3) - 5
	return t

def f_der(x):
	t = 30 * math.cos(x) + 3*x*x
	return t

def newtoncheck(x):
	for i in range(4):
		if abs(f(x)) > 0.0001:
			x = x - f(x)/f_der(x)
			print(f(x))
		else:
			print ('number of iterations',i)
			print ('root',x)
			break
	return