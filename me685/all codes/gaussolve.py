def myGauss(m):
    #eliminate columns
    k = 0
    for i in range(len(m[0])):
        for j in range(i+1 , len(m)):
                for k in range(len(m[0])):
                        r = m[i][k] * m[j][k] / m[i][i]
                        m[j][k] = m[j][k] - r




        #now backsolve by substitution
    print (m)
    ans = []
    m.reverse() #makes it easier to backsolve
    for sol in range(len(m)):
            if sol == 0:
                ans.append(m[sol][-1] / m[sol][-2])
            else:
                inner = 0
                #substitute in all known coefficients
                for x in range(sol):
                    inner += (ans[x]*m[sol][-2-x])
                #the equation is now reduced to ax + b = c form
                #solve with (c - b) / a
                ans.append((m[sol][-1]-inner)/m[sol][-sol-2])
    ans.reverse()
    return ans
    
