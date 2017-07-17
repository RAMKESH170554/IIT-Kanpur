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

def LU(m):
	n = len(m)
	l = unit(n)
	u = [[0 for i in range(n)] for j in range(n)]
	for i in range(n):
		for j in range(n):
			if j<i:
				l[j][i] = 0
			else:
				l[j][i] = m[j][i]
				for k in range(i):
					l[j][i] = l[j][i] - l[j][i]*u[k][i]
		for j in range(n):
			if j<i:
				u[i][j] = 0
			elif j == i:
				u[i][j] = 1
			else:
				u[i][j] = m[i][j]/l[i][i]
				for k in range(i):
					u[i][j] = u[i][j] -(l[i][k] * u[k][j])/l[i][i]
	return l,u

def backsubs(u,y):
	x = [0 for i in range(len(u))]
	n = len(u)
	for i in range(len(u)-1, -1,-1):
		t = 0
		for j in range(i+1, n, 1):
			t = t+ u[i][j] * x[j]
		x[i] = (y[i] - t) / u[i][i]
	return x

def fwdsubs(l,b):
	y = [0 for i in range(len(l))]
	n = len(l)
	for i in range(len(l)):
		t = 0
		for j in range(i):
			t = t+ l[i][j] * y[j]
		y[i] = (b[i] - t) / l[i][i]
	return y


def inv(m):
	[l,u] = LU(m)
	n = len(m)
	I = unit(n)
	X = [[0 for i in range(n)] for j in range(n)]
	for i in range(n):
		X[i] = fwdsubs(l,I[i])
		X[i] = backsubs(u,X[i])
	for i in range(n):
		for j in range(i+1,n):
			t = X[i][j]
			X[i][j] = X[j][i]
			X[j][i] = t
	return X