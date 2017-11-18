import random
test_cases = 10
test_no = 1
MAX_VERT = 1000
while test_no <= test_cases:
	# number of vertices
	n = random.randint(1, MAX_VERT)
	components = n
	print n

	# graph
	adj = []
	for i in range(n):
		adj.append([])

	# union-find
	parent = [i for i in range(n)]
	size = [1]*n
	def find(x):
		if x == parent[x]:
			return x
		parent[x] = find(parent[x])
		return parent[x]
	def union(x, y):
		x = find(x)
		y = find(y)
		if(x!=y):
			if size[x] <= size[y]:
				parent[y] = x
				size[x] += size[y]
			else:
				parent[x] = y
				size[y] += size[x]

	# add edges
	for i in range(n):
		for j in range(n):
			if i==j:
				continue
			if random.random() <= 1.0/n+0.01: 
				# According to Erdos' theorem, 1.0/n is transition probability
				# which makes graph weakly connected with high probability
				# Verification done via disjoint set
				adj[i].append(j)
				if(find(i)!=find(j)):
					components = components - 1
					union(i, j)
	print components
	if components == 1:
		f = open("tests2/"+str(test_no)+".in", "w")
		f.write(str(n)+"\n");
		for i in range(n):
			for j in range(len(adj[i])):
				f.write(str(adj[i][j])+" ")
			f.write("-1\n");
		print "Test", test_no, ": n =", n
		test_no = test_no + 1
	else:
		print "Retrying random graph"