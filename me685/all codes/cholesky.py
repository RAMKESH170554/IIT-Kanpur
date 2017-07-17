
def cholesky(m):
	n = len(m)
	l = unit(n)
	for i in range(n):
		x = 0
		for k in range(0,i):
			x = x + l[i][k] * l[i][k]
		if l[i][i] - x > 0:
			l[i][i] = math.sqrt(m[i][i] - x)
		if l[i][i] - x < 0:
			return 'not psd'
		for j in range(i+1,n):
			y = 0
			for k in range(0,i):
				y = y + l[j][k] * l[i][k]
			if l[i][i] == 0:
				return 'one of diag element is 0'
			else:
				l[j][i] = (m[j][i] - y) / l[i][i]
	return l