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

def QR(A):

	m = len(A)
	n = len(A[0])
	R = [[0 for i in range(n)] for j in range(n)]
	Q = [[0 for i in range(n)] for j in range(m)]
	Anew = [[0 for i in range(n)] for j in range(m)]
	for j in range(n):
		for i in range(0,j):
			t = 0
			for k in range(m):
				t = t + Q[k][i] * A[k][j]
			R[i][j] = t
		for k in range(m):
			t = 0
			for i in range(j):
				t = R[i][j]*Q[k][i] + t
			Anew[k][j] = A[k][j] - t
		
		t = 0

		for i in range(m):
			t = t + Anew[i][j] * Anew[i][j] 
		R[j][j] = t**(.5)
		
		if R[j][j] != 0:
			for i in range(m):
				Q[i][j] = Anew[i][j]/R[j][j]
		else:
			print('fill some q vectors')
	return Q,R

def QR_iterations(S):
	for k in range(1000):
		[q,r] = QR(S)
		#print (S)
		S = multiply(r,q)
	n = len(S)
	print('roots are')
	for i in range(n):
		print(S[i][i])
	return S

def f(x):
	t = x**4 - 13*x*x*x + 35*x*x- 40*x+24
	return t