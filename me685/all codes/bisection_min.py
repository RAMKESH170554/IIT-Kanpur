import math

def f(x):
	t = math.log(x) - math.exp(x) #pow(x,4) - 14*pow(x,3) + 60*x*x - 70*x
	return t

def bisection():
	a = 0
	b = 2
	#print('min in between',a,'and',b)
	#xpre = 0
	for i in range(100):
		x2 = (a+b)/2
		x1 = (a+x2)/2
		x3 = (b+x2)/2
		if abs(x2 - a) + abs(x2 - b) > 0.00001:
			if f(x2) > f(x1):
				b = x2
				#x2 = (a+b)/2
			elif f(x2) > f(x3):
				a = x2
				#x2 = (a+b)/2
			else:
				a = x1
				b = x3
		else:
			return x2
	return