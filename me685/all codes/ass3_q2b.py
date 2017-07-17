
import math

#def f(x):
#	t = math.log(x) - math.exp(x) #pow(x,4) - 14*pow(x,3) + 60*x*x - 70*x
#	return t

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

def f(a):
	x =[[107.62418353423415], [4.51039261066524], [-24.1853585452335], [-87.76963080742327]]# [[25.325030957166707], [105.47529905964122], [-55.68440925996993]]
	fun = [[20],[51.58],[68.73],[75.46],[74.36],[67.09],[54.73],[37.98],[17.28]]
	t = [[0],[58],[68.73],[75.46],[36],[67.09],[0.73],[37.98],[17.28]]
	n = len(fun)
	for i in range(n):
		t[i][0] = i*0.25
	#l = x[0][0]
	#x = x + [[l/2]]
	#x[0][0] = l/2
	y = 0
	for i in range(n):
		fun[i][0] = x[0][0] + x[1][0] * t[i][0] + x[2][0] * (t[i][0] **2) + x[3][0]*math.exp(a *t[i][0]) - fun[i][0]
		y = y + fun[i][0] ** 2
	return y