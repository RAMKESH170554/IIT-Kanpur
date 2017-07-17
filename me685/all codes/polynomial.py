import math
def cubic(x,f):
	n = len(x)
	m = [[0 for i in range(n)] for j in range(n)]
	for i in range(n):
		for j in range(n):
			m[i][j] = pow(x[i],j)
	a = inverse(m)
	coeff = multiply(a,f)
	print("a+bx+cx2+dx3")
	return (coeff)

def lagrange(x,f):
	n = len(x)
	for i in range(0,n):
		t = 1
		for j in range(n):
			if i!= j:
				t = t*(x[i] - x[j])
		
		f[i][0] = f[i][0]/t
	print('a(x-x1)(x-x2)(x-x3)+b(x-x0)(x-x2)(x-x3)+c(x-x0)(x-x1)(x-x3)+d(x-x0)(x-x1)(x-x2)')
	print(f)

def newton(x,f):
	g = [1,0,0,0]
	m = [[1,0,0,0] for i in range(len(x))]
	for i in range(1,4):
		t = 1
		for j in range(0,i):
			t = t * (x[i] - x[j])
		for k in range(i,len(x)): 
			m[k][i] = t
	a = inverse(m)
	coeff = multiply(a,f)
	print("a+b(x-x0)+c(x-x0)(x-x1)+d(x-x0)(x-x1)(x-x2)")
	print (coeff)

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