import math 

def f(x):
	t = (x)
	return t

def F(x):
	h1 = 0.0001
	f_diff = (f(x+h1) - f(x-h1))/(2*h1)
	return f_diff

def inp_8(x,a):
	n = len(x)
	f1 = [[0] for i in range(n)]
	for i in range(n):
		f1[i][0] = f(x[i])
	
	m = [[0 for i in range(n)] for j in range(n)]
	for i in range(n):
		for j in range(n):
			m[i][j] = pow(x[i],j)
	u = inverse(m)
	coeff = multiply(u,f1)
	#print('polynomial coefficients: a+ bx + cx2 +...')
	#print(coeff)
	t = 0
	for i in range(n):
		z = pow(a,i)
		t = t+ coeff[i][0] * z
	print('value from 8th deg poly at',a,'is',t)
	print('value from actual function',f(a))

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

def Splines(point,op):
    data = points(point)
    np1=len(data)
    n=np1-1
    X,Y = zip(*data)
    X = [float(x) for x in X]
    Y = [float(y) for y in Y]
    a = Y[:]
    b = [0.0]*(n)
    d = [0.0]*(n)
    h = [X[i+1]-X[i] for i in range(n)]
    alpha = [0.0]*n
    for i in range(1,n):
        alpha[i] = 3/h[i]*(a[i+1]-a[i]) - 3/h[i-1]*(a[i]-a[i-1])
    c = [0.0]*np1
    L = [0.0]*np1
    u = [0.0]*np1
    z = [0.0]*np1
    L[0] = 1.0; u[0] = z[0] = 0.0
    for i in range(1,n):
        L[i] = 2*(X[i+1]-X[i-1]) - h[i-1]*u[i-1]
        u[i] = h[i]/L[i]
        z[i] = (alpha[i]-h[i-1]*z[i-1])/L[i]
    L[n] = 1.0; z[n] = c[n] = 0.0
    for j in range(n-1, -1, -1):
        c[j] = z[j] - u[j]*c[j+1]
        b[j] = (a[j+1]-a[j])/h[j] - (h[j]*(c[j+1]+2*c[j]))/3
        d[j] = (c[j+1]-c[j])/(3*h[j])
    splines = []
    for i in range(n):
        splines.append((a[i],b[i],c[i],d[i],X[i]))
    t = 0.0
    for i in range (3):
        t = t + splines[3][i] * pow((op - point[3]),i)
    print('value from splines is:',t)
    return 

def points(X):
    v = [[0,0] for i in range(len(X))]
    for i in range(len(X)):
        v[i][0] = X[i]
        v[i][1] = f(X[i])
    return v
