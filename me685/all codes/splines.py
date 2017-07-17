import math 

def f(x):
    t = math.cos(10 * math.acos(x) + math.pi/6) + math.log(2*x + 5)
    return t

def Splines(point,op):
    data = points(point)
    np1=len(data)
    n=np1-1
    X,Y = zip(*data)
    X = [float(x) for x in X]
    Y = [float(y) for y in Y]
    a = Y[:]
    b = [0.0]*(n)
    d = [0.0]*(n)
    h = [X[i+1]-X[i] for i in range(n)]
    alpha = [0.0]*n
    for i in range(1,n):
        alpha[i] = 3/h[i]*(a[i+1]-a[i]) - 3/h[i-1]*(a[i]-a[i-1])
    c = [0.0]*np1
    L = [0.0]*np1
    u = [0.0]*np1
    z = [0.0]*np1
    L[0] = 1.0; u[0] = z[0] = 0.0
    for i in range(1,n):
        L[i] = 2*(X[i+1]-X[i-1]) - h[i-1]*u[i-1]
        u[i] = h[i]/L[i]
        z[i] = (alpha[i]-h[i-1]*z[i-1])/L[i]
    L[n] = 1.0; z[n] = c[n] = 0.0
    for j in range(n-1, -1, -1):
        c[j] = z[j] - u[j]*c[j+1]
        b[j] = (a[j+1]-a[j])/h[j] - (h[j]*(c[j+1]+2*c[j]))/3
        d[j] = (c[j+1]-c[j])/(3*h[j])
    splines = []
    for i in range(n):
        splines.append((a[i],b[i],c[i],d[i],X[i]))
    t = 0.0
    for i in range (3):
        t = t + splines[0][i] * pow((op - point[0]),i)
    
    return t

def points(X):
    v = [[0,0] for i in range(len(X))]
    for i in range(len(X)):
        v[i][0] = X[i]
        v[i][1] = f(X[i])
    return v

