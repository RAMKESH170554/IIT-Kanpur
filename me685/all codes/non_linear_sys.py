import math

def f(x):
	t = 16*(pow(x[0],4) + pow(x[1],4)) + pow(x[2],4) - 15
	return t

def g(x):
	t = (pow(x[0],2) + pow(x[1],2) + pow(x[2],2)) - 3
	return t

def h(x):
	t = pow(x[0] , 3) - x[1]
	return t

def grad(x):
	f1 = [64*pow(x[0],3),64*pow(x[1],3),4*pow(x[2],3)]
	g1 = [2*x[0],2*x[1],2*x[2]]
	h1 = [3*pow(x[0],2),-1,0]
	J = [f1,g1,h1]
	return J
		
def non_linear(x):
	
	for i in range(100000):
		F = [[f(x)],[g(x)],[h(x)]]
		t = 0
		for j in range(3):
			t = t + pow(F[j][0],2)
		if t >= 0.00003:
			J = grad(x)
			inv_g = inverse(J)
			update = multiply(inv_g,F)
			for j in range(3):
				x[j] = x[j] - update[j][0]
		else:
			break
	print ('solution of eqn',x)
	return 

def inverse(m):
	n = len(m)
	q = unit(n)
	for i in range(n):
		m[i] = m[i] + q[i]

	I = [[0 for i in range(n)] for j in range(n)]
	
	for i in range(n):
		for j in range(n,2*n,1):
			if j-n == i:
				m[i][j] = 1
			else:
				m[i][j] = 0
	for i in range(n):
		x = i
		for j in range(i+1,n):
			y = abs(m[i][i])
			if y < abs(m[j][i]):
				x=j
				y = abs(m[j][i])
		for j in range(2*n):
			temp = m[i][j]
			m[i][j] = m[x][j]
			m[x][j] = temp
		temp = m[i][i]
		for k in range(2*n):
			m[i][k] = m[i][k]/temp
		for k in range(n):
			if k != i:
				p = m[k][i]
				for h in range(2*n):
					m[k][h] = m[k][h] - p*m[i][h]
	for i in range(n):
		for j in range(n):
			I[i][j] = m[i][n+j]
	return I


def multiply(a,b):
	m = len(a)
	n = (len(a[0]))
	p = len(b[0])
	c = [[0 for j in range(p)] for i in range(m)]
	if n == len(b):
		for i in range(m):
			for k in range(p):
				for j in range(n):
					c[i][k] = c[i][k] + a[i][j] * b[j][k]
	else:
		return 'give input such that col of a=row of b'
	return c

def unit(n):
	g = []
	for i in range(n):
		x = []
		for j in range(n-1,-1,-1):
			if i==j:
				x = x + [1]
			else:
				x = x + [0]
		g = [x] + g
	return g
