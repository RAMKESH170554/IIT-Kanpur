import math

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

k1 = 1
k2 = 100

def f(t,Z):
	n = 3
	h = [[0] for i in range(n)]
	h[0][0] = -Z[0][0]*k1    # + math.exp(t)#22.5 - 0.5*Z[1][0] - Z[0][0]
	h[1][0] = k1 * Z[0][0] - k2*Z[1][0] #28.75 - Z[1][0] + 0.5*Z[0][0] + 0.25*Z[2][0]
	h[2][0] = Z[1][0] * k2  #17.5 - 0.75*Z[2][0] + 0.25*Z[1][0]
	return h

def jac(h):
	n = 3
	#k1 = 1
	#k2 = 1000
	J = [[0 for j in range(n)] for i in range(n)]
	mul = [[0 for j in range(n)] for i in range(n)]
	J[0][0] = -k1
	J[1][0] = k1
	J[1][1] = -k2
	J[2][1] = k2
	In = unit(n)
	for i in range(n):
		mul[i][i] = J[i][i]*h - In[i][i]
	mul = inverse(mul)
	return mul

def newton_step(t,Z0,h): # as step h is small to reach b error is less in final value
	n = 3
	y1 = [[0] for i in range(n)]
	for i in range(n):
		y1[i][0] = Z0[i][0] - 0.01
	#temp = [[0] for i in range(n)]
	update = [[0] for i in range(n)]
	for j in range(10000):
		for i in range(n):
			update[i][0] = Z0[i][0] - y1[i][0] + h * f(t+h,y1)[i][0]
		for i in range(n):
			y1[i][0] = y1[i][0] - multiply(jac(h),update)[i][0]
		t = 0
		for i in range(n):
			t = t + multiply(jac(h),update)[i][0]
		if abs(t) < 0.00001:
			break
		#else:
		#	y1 = temp
	return y1

def b_euler(t,Z0,b,h):# take h small to correct for error h = 0.001
	#p = (b-t)/h
	n = 3
	y2 = [[0] for i in range(n)]
	for i in range(10000000):
		y2 = newton_step(t,Z0,h)
		Z0 = y2
		
		if t > b:
			break
		else:
			t = t+h
	return y2