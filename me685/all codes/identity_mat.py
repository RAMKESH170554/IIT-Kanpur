def makeidentity(m):
	det = 1
	max = 0
	n = len(m)
	for k in range(n):
		for j in range(k,n):
			if max <= abs(m[j][k]):
				max = m[j][k]
				l = j
		if max == 0:
			det = 0
			return max
			exit
		else:
			temp = m[k]
			m[k] = m[l]
			m[l] = temp
		det = det * m[k][k]
		for r in range(n):
			m[r][k] = m[r][k] / m[k][k]
		for j in range(n):
			if j != k:
				m[j][k] = m[j][k] - m[j][k] * m[k][k] 
	det = det * m[n-1][n-1]
	if m[n-1][n-1] == 0:
		return m[n-1][n-1]
	else:
		for i in range(n):
			m[n-1][i] = m[n-1][i] / m[n-1][n-1]
	return m