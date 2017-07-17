import math

def F(x):
	t = 2*x[0]*x[0] - pow(x[0],4) + pow(x[0],6)/6 + x[0] * x[1] + x[1]*x[1] / 2
	return t

def g(x):
	t = 2*x[0]*x[0] - 12*x[0] - x[1] + 23
	return t

def f(x,c):
	t = F(x) + c*max(0,g(x))*max(0,g(x))
	return t

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

def grad(x,c):
	if 0 < g(x):
		f1 = [4*x[0]-4*pow(x[0],3) + pow(x[0],5) + x[1] + 2*4*c*x[0]*g(x) - 12*2*c*g(x),
					x[0]+x[1]-c*2*g(x)]
	else:
		f1 = [4*x[0]-4*pow(x[0],3) + pow(x[0],5) + x[1] , x[0]+x[1]]
	return f1

def steepDes(eg,ea,er,x,a,c):
	#print('1')

	g_norm = 0
	for k in range(100000):
		gprev = g_norm
		g = grad(x,c)
		for i in range(len(g)):
			g_norm = g[i]*g[i] + g_norm
		g_norm = g_norm**(0.5)
		if abs(g_norm - gprev) <= eg:
			return x
		else:
			d = g
			for i in range(len(g)):
				d[i] = d[i] / g_norm
		alpha = newton(x,c,d,a)
		if alpha <= 0:
			#print('2')
			print('alpha is neg',alpha,'. so repeat with alpha + 0.1')
			a = a + 0.1
			continue
		x_prev = x
		for j in range(len(x)):
			x[j] = x[j] - alpha*d[j]
		if abs(f(x,c) - f(x_prev,c)) <= (ea + er * abs(f(x_prev,c))):
			break
		elif k > 100000:
			return 'max iterations exceeded'
		else:
			continue
	return x

def alpha_func(x,c,d,a):

	f_diff = 0
	D = d
	for i in range(len(d)):
		#print('3')
		D[i] = x[i] - a*d[i]

	g = grad(D,c)
	#print(g)
	for i in range(len(d)):
		#print('5')
		f_diff = f_diff + d[i] * g[i]
		#print(f_diff)
	return f_diff

def newton(x,c,d,a):
	h = 0.0001
	aprev = 0
	for i in range(10000):
		if abs(a - aprev) > 0.0001:
			#print('4')
			deri = (alpha_func(x,c,d,a+h) - alpha_func(x,c,d,a-h))/(2*h)
			aprev = a
			a = a - alpha_func(x,c,d,a) / deri
		else:
			#print('6')
			break
	return a


def mini_x(a):
	c = [1,10,100]
	l=0
	i = 0

	for cvalue in c:
		l = steepDes(0.0001,0.0001,0.0001,[4,8],a,cvalue)
		if g(l) <= 0:
			print('minimum at')
			print(l)
			print('for c =',c[i])
			i= i+1
		else:
			print(l,'for c =',c[i])
			i = i+1
	return