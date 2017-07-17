import math

def f(t,Z):
	n = 2
	h = [[0] for i in range(n)]
	h[0][0] = 6*Z[0][0] - Z[0][0]*Z[1][0]#Z[0][0] - Z[1][0] + math.exp(t)#22.5 - 0.5*Z[1][0] - Z[0][0]
	h[1][0] = 2*Z[0][0]*Z[1][0] - 8*Z[1][0] #28.75 - Z[1][0] + 0.5*Z[0][0] + 0.25*Z[2][0]
	#h[2][0] = 17.5 - 0.75*Z[2][0] + 0.25*Z[1][0]
	return h

def RK4_sys(t,Z0,b,h):
	#h = 0.001
	n = 2
	y1 = [[0] for i in range(n)]
	y2 = [[0] for i in range(n)]
	y3 = [[0] for i in range(n)]
	y4 = [[0] for i in range(n)]
	y = [[0] for i in range(n)]
	temp = [[0] for i in range(n)]
	for i in range(1000000):
		if t < b:
			for i in range(n):
				y1[i][0] = h * (f(t,Z0))[i][0]
			for i in range(n):
				temp[i][0] = Z0[i][0] + y1[i][0] * 0.5
			for i in range(n):
				y2[i][0] = h * (f(t + h/2 ,temp))[i][0]
			for i in range(n):
				temp[i][0] = Z0[i][0] + y2[i][0] * 0.5
			for i in range(n):
				y3[i][0] = h * (f(t + h/2 ,temp))[i][0]
			for i in range(n):
				temp[i][0] = Z0[i][0] + y3[i][0]
			for i in range(n):
				y4[i][0] = h * (f(t + h ,temp))[i][0]
			for i in range(n):
				y[i][0] = (y1[i][0] + 2* y2[i][0] + 2* y3[i][0] + y4[i][0]) / 6
			for i in range(n):
				Z0[i][0] = y[i][0] + Z0[i][0]
			t = t + h
		else:
			break
	return Z0