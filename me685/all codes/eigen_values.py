from random import randint

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

def power(A):
	n = len(A)
	x = [[1] for i in range(n)]
	#print('x =',x)
	maxi = 0
	z = x
	for i in range(1000):
		#print(1)
		k = [[0] for j in range(n)]
		z = multiply(A,x)
		t = 0
		#for j in range(n):
		#	t = t + z[j][0]*z[j][0]
		#t = t**(0.5)
		#for j in range(n):
		#	z[j][0] = z[j][0] / t 
		for j in range(n):
			k[j][0] = z[j][0]
		#print(2,k)
		l = maxi
		maxi = 0
		for j in range(n):
			if abs(x[j][0]) > abs(maxi):
				maxi = x[j][0]
		for j in range(n):
			k[j][0] = k[j][0] / maxi
		
		if abs(l - maxi) <= 0.00001:
			#print(l,x)
			for d in range(n):
				x[d][0] = x[d][0] / pow(l,i+1)
			return l,x
		else:
			#print(4,x)
			x = k
			continue
	return

def trans(C):
    n = len(C)
    m = len(C[0])
    T = [[0 for j in range(n)] for i in range(m)]
    for i in range(m):
        for j in range(n): 
            T[i][j] = C[j][i]
    return T


def deflat(Q,e,v):
    n = len(Q)
    vT = trans(v)

    g = multiply(vT,v) 
    h = e / g[0][0] 
    B = multiply(v,vT)

    for i in range(n):
        for j in range(n):
            B[i][j] = Q[i][j] - h * B[i][j]
    return B

def eigenval(S):
	n = len(S)

	for i in range(n):
		[E,V] = power(S)
		print('eigen value and vector',E,V)
		S = deflat(S,E,V)
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
