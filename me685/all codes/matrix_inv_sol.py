
def inverse(m):
	n = len(m)
	c = len(m[0])
	q = unit(n)
	for i in range(n):
		m[i] = m[i] + q[i]

	I = [[0 for i in range(n)] for j in range(n)]
	
	for i in range(n):
		for j in range(c,2*n+1,1):
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
		for j in range(2*n+1):
			temp = m[i][j]
			m[i][j] = m[x][j]
			m[x][j] = temp
		temp = m[i][i]
		for k in range(2*n+1):
			m[i][k] = m[i][k]/temp
		for k in range(n):
			if k != i:
				p = m[k][i]
				for h in range(2*n + 1):
					m[k][h] = m[k][h] - p*m[i][h]
	for i in range(n):
		for j in range(n):
			I[i][j] = m[i][c+j]
	r = [[0] for i in range(n)]
	for i in range(n):
		r[i][0] = m[i][n]
	return I,r


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