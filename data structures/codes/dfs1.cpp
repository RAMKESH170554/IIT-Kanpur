#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adjList;
vector<vector<int> > adjList2;
int n,tim=0,ctr=0;
vector<int> discover;
vector<int> a;
vector<int> finish;
vector<vector<int> > newnode;
vector<int> part;
vector<int> ar;
vector<bool> vis;

void dfs(int vertex){ // normal dfs
	vis[vertex]=true;
	tim++;
	discover[vertex] = tim;
	int siz=adjList2[vertex].size();
	for(int i=0;i<siz;i++){
		if(vis[adjList2[vertex][i]]==false)	
			dfs(adjList2[vertex][i]);
	}
	tim++;
	finish[vertex]= tim;
}

void dfs2(int vertex){ // dfs for strongly connected components
	vis[vertex]=true;

	int siz=adjList[vertex].size();
	for(int i=0;i<siz;i++){
		if(vis[adjList[vertex][i]]==false){
			part[adjList[vertex][i]] = ctr;
			dfs2(adjList[vertex][i]);
		}
			if(part[vertex] != part[adjList[vertex][i]]){
				newnode[part[vertex]].push_back(part[adjList[vertex][i]]);//maintains nodes for strngly connected components
			}	
	}
}

void topological(){ // topological sorting
	for(int i =0;i<n;i++)
		a[i] = finish[i];
		std::sort (a.begin(), a.begin()+n);
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n;j++){
			if(finish[j] == a[i]){
				a[i] = j;
				finish[j] = -1;
				break;
				}				
		}
	}
}

int main(){
	int x;

	scanf("%d",&n);
	newnode.resize(n+2);
	part.resize(n+2);
	ar.resize(n+2);
	a.resize(n+2);
	finish.resize(n+2);
	discover.resize(n+2);
	vis.resize(n+2);
	adjList.resize(n+2);
	adjList2.resize(n+2);

	for(int i=0;i<n;i++)	
		vis[i]=false;

	for(int i=0;i<n;i++){
		scanf("%d",&x);
		while(x!=-1){
			adjList[i].push_back(x);
			adjList2[x].push_back(i);
			scanf("%d",&x);
		}
	}

	for(int i=0;i<n;i++){
		if(vis[i]==false)	
			dfs(i);
	}
	
	topological();
	
	for(int i=0;i<n;i++)	
		vis[i]=false;
		
	for(int i=n-1;i>=0;i--){
		if(vis[a[i]]==false){
			ctr++;	
			part[a[i]] = ctr;
			dfs2(a[i]);
		}
	}

/*
7
5 -1
2 3 -1
3 -1
4 1 -1
1 -1
6 1 -1
0 -1

10
7 2 -1
6 0 -1
3 -1
5 -1
8 0 -1
9 -1
8 -1
6 5 -1
7 -1
2 -1

9
6 -1
4 -1
8 -1
0 -1
7 -1
7 2 -1
8 3 -1
1 -1
5 -1

8
2 1 -1
4 -1
6 3 -1
5 -1
2 5 -1
6 -1
-1
1 5 -1

5
1 -1
2 3 -1
0 4 -1
4 -1
3 -1

*/

	int id[ctr+1];
	printf("%d",ctr);
	
	for(int j=1;j<=ctr;j++){
		for(int i=0;i<n;i++){ // maintains id for each components
			if(part[i]==j){
				id[j] = i;
				break;
			}
		}
	}
	
	int p[ctr];
	
	for(int i=1;i<=ctr;i++)
		p[i-1] = id[i];
		
	sort(p,p+ctr);
	
	for(int i=0;i<ctr;i++)
		for(int j=1;j<=ctr;j++)//ranks id of ith component with a[i]
			if(p[i] == id[j])
				a[j]=i;

	vector<vector<int > > node;
	node.resize(ctr);
	for(int i=1;i<=ctr;i++){
		int k = newnode[i].size();
		for(int j=0;j<k;j++)
			node[a[i]].push_back(a[newnode[i][j]]); // it makes new list with ranks of ids
	}
	
		for(int i=0;i<ctr;i++){
			printf("\n");
		
		std::sort (node[i].begin(), node[i].end());//sorts in ascending order
		std::vector<int>::iterator it;
  it = std::unique (node[i].begin(), node[i].end());  // manages repitition of edges between components 
  node[i].resize( std::distance(node[i].begin(),it) );
  int k = node[i].size();
		for(int j=0;j<k;j++){
			printf("%d ",node[i][j]);
		}
		printf("-1");
	}

	return 0;
}
