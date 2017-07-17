
n = 6 #number of unknown variables
N = 3 #number of intervals
h = 1/N

def f(t,z):
	#H = [[0] for i in range(n)]
	H = [[0] for i in range(2)]
	H[0][0] = (z[1][0]+z[3][0])/2    # + math.exp(t)#22.5 - 0.5*Z[1][0] - Z[0][0]
	H[1][0] = 10*((z[0][0] +z[2][0])**3)/8 + 3*(z[0][0]+z[2][0])/2 + t*t
	return H

def deriv(Z3,i):
	r = -h*30*(Z3[i-1][0] + Z3[i+1][0])*(Z3[i-1][0] + Z3[i+1][0])/8 - 1.5*h
	return r

def jac(t,Z): #Z is vector of unknown and known variables
	J = [[0 for i in range(n)] for j in range(n)]
	k = 1	
	for i in range(1,n):
		J[i-1][i] = 1
		J[i][i-1] = -1
	#for i in range(2):
	#	J[2*i][2*i+2] = -h/2
	for i in range(n-1):
		if i%2 == 0:
			J[i][i] = -h/2
		else:
			J[i][i] = deriv(Z,k)
			J[i-1][i+1] = -h/2
			J[i+2][i] = deriv(Z,k+2)
			k = k+2
	J[n-1][n-1] = 1
	J[n-2][n-1] = -h/2

#	J[4][5] = -h/2
#	for i in range(3): # n/2 = 3
#		#J[2*i][2*i + 2] = -h/2
#		J[2*i][2*i] = -h/2
#	J[1][1] = -30*h*(0 + Z[1][0])*(0 + Z[1][0])/8 - 3/2
#	J[3][3] = -30*h*(Z[1][0] + Z[3][0])*(Z[1][0] + Z[3][0])/8 - 3/2
#	J[3][1] = J[3][3] #-30*h*(Z[1][0] + Z[3][0])*(Z[1][0] + Z[3][0]) - 3/2
#	J[5][3] = -30*h*(Z[3][0] + 1)*(Z[3][0] + 1)/8 - 3/2
	#J = inverse(J)
	#for i in range(n):
	#	for j in range(n):
	#		J[i][j] = J[i][j] / h
	return J

def newfunc(t,Z1): #Z1 is vector of unknown and known variables
	O = [[0] for j in range(n)]
	
	k = 1
	#l = [[0] for i in range(4)]
	for i in range(0,n,2):

		p = f(t+(i+1)*h/2,Z1[i:(i+4)])
		O[i][0] = Z1[k+1][0] - Z1[k-1][0] - h*p[0][0]
		O[i+1][0] = Z1[k+2][0] - Z1[k][0] - h*p[1][0]
		k=k+1
	return O

def newton(t,Z0): #Z0 is vector of known and unknown variables
	Z2 = [[0] for i in range(n)]
	
	G = [[0] for j in range(n)]
	
	Z2[n-1][0] = Z0[n+1][0]
	for i in range(n-1):
		Z2[i][0] = Z0[i+1][0]
	for j in range(100):
		
		G =  multiply(jac(t,Z0),newfunc(t,Z0))
		for i in range(n):
			Z2[i][0] = Z2[i][0] - G[i][0]
		
		x = 0
		for i in range(n-1):
			x = x + abs(Z0[i+1][0] - Z2[i][0])

		Z0[n+1][0] = Z2[n-1][0]
		for i in range(n-1):
			Z0[i+1][0] = Z2[i][0]

		if abs(x/n) < 0.1:
			break
	return Z2


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

