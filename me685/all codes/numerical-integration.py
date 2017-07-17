import math

def f(x):
	t = math.exp(x)
	return t

def integ_mid(a,b):
	n = 100000
	h = abs(a-b) / n
	area = 0

	for i in range(n):

		x = a + h/2
		area = area + h * f(x)
		a = a + h
	return area

def integ_sim(a,b):
	n = 100000
	h = abs(b-a)/(2*n)
	area = 0
	for i in range(n):
		xpre = a #+ h/2 depending on function is valid at a or not
		x = xpre+h
		xnext = h+x
		area = area + (h/3)*(f(xpre) + 4*f(x) + f(xnext))
		a = a + 2*h
	return area

def trap(a,b,n):
	#n = 100000 for romberg integration
	h = abs(a-b)/n
	sum = 0
	for i in range(n-1):
		x = a + h
		sum = sum + f(x)
		a = a + h
	area = (h/2)*(2*sum + f(a) + f(b))
	return area

def romberg(a,b):
	alpha = 0.5
	n = 6
	eps = 0.0000001
	J = [[0 for i in range(100)] for j in range(100)]
	h = b - a
	J[0][0] = trap(a,b,1)
	j = 1
	while(True):#for j in range(1,n):
		J[0][j] = trap(a,b,2**j)
		for i in range(1,j+1):
			J[i][j] = (J[i-1][j] - J[i-1][j-1] * pow(alpha,i))/(1 - pow(alpha,i))
		if abs(J[j][j] - J[j-1][j]) < eps:
			print(j)
			return J[j][j]
		else:
			j = j+1   #continue

	return

def adap_quad(a,b,e):
	n = 3
	h = abs(b-a)/n
	err = 9
	est1 = 0
	est2 = 0
	area = 0

	for k in range(n):
		i = 0
		while(err > e/n):
			est1 = trap(a,a+h,2**i)
			est2 = trap(a,a+h,2**(i+1))
			err = abs(est1 - est2)
			i = i + 1
		a = a + h
		err = 9
		area = area + est2
	return area