import math

def F(x,a):
	t = x[0][0] + x[1][0] * a + x[2][0] * a*a + x[3][0] * math.exp(x[4][0]*a)
	return t

def Jac(x,tT):
	n = len(tT)
	m = len(x)
	h = [[0 for i in range(m)] for j in range(n)]
	for j in range(3):
		for i in range(n):
			h[i][j] = pow(tT[i][0],j)
	for i in range(n):
		h[i][3] = math.exp(tT[i][0] * x[4][0])
		h[i][4] = tT[i][0] * x[3][0] * math.exp(tT[i][0]* x[4][0])
	
	return h

def E(x1x,t1t,f1f):
	o = [[0] for i in range(len(f1f))]
	n = len(f1f)
	for i in range(n):
		o[i][0] = (- f1f[i][0] + F(x1x,t1t[i][0]) )
	
	#et = trans(o)
	#r = multiply(et,o)
	return o

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

def trans(C):
	n = len(C)
	m = len(C[0])
	T = [[0 for j in range(n)] for i in range(m)]
	for i in range(m):
		for j in range(n): 
			T[i][j] = C[j][i]
	return T


def leven(x,eps,lam,uf): #requires value near to actual ans 

	t = [[0]for j in range(9)]
	#f = t
	n = len(t)
	for i in range(n):
		t[i][0] = 0.25*i
	f = [[20],[51.58],[68.73],[75.46],[74.36],[67.09],[54.73],[37.98],[17.28]]
	temp = [[0]for j in range(5)]
	dx = [[0]for j in range(5)]
	for k in range(1000):
		
		#gra = grad(x,t,f)
		#gra = norma(gra)
		#dx = x
		g = multiply(trans(Jac(x,t)),E(x,t,f))
		J = trans(Jac(x,t))
		hess = multiply(J,Jac(x,t))
		#hess = norma(hess)
		m = len(hess)
		for i in range(m):
			hess[i][i] = hess[i][i] * (lam +1)
		dx = solve(hess,g)
		for i in range(m):
			#xpre[i][0] = x[i][0]
			temp[i][0] = x[i][0] - dx[i][0]

		if norma(E(temp,t,f)) < eps:
			return x
		else:
			if norma(E(temp,t,f)) < norma(E(x,t,f)):
				lam = lam/uf
				#xpre = x
				x = temp
			else:
				lam = lam * uf
				continue
	return x	

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
			tep = m[i][j]
			m[i][j] = m[x][j]
			m[x][j] = tep
		tep = m[i][i]
		for k in range(2*n):
			m[i][k] = m[i][k]/tep
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

def solve(ac,cd):
	aac = inverse(ac)
	value = multiply(aac,cd)
	return value

def norma(k):
	n = len(k)
	y = 0
	for i in range(n):
		y = y + k[i][0]*k[i][0]
	#for i in range(n):
	#	k[i][0] = k[i][0] / y
	return y**(0.5)