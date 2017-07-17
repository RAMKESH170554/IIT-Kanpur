import math

def F(x):
	t = math.log(x)
	return t


def richardson(x):

	h = 0.00001
	a = 0.001

	f1 = F(x+h)
	f2 = F(x+a*h)
	f4 = F(x+a*a*h)
	f3 = (f2 - pow(a,2)*f1) / (1 - pow(a,2))
	f5 = (f4 - pow(a,2)*f2) / (1 - pow(a,2))
	f6 = (f5 - pow(a,2)*f3) / (1 - pow(a,2))
	print ('extrapolated value at',x)
	return f6
