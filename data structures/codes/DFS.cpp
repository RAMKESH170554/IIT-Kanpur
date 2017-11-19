#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int > > wts;
vector<vector<int > > adjlist;
vector<int > vis;
vector<int > dist;
vector<int > distances;

int start,n,nheap;


void min_heapify(int i){
	int r = 2*i+1, l = 2*i, max = i;
	
	if((l <= nheap) && (dist[l] < dist[i]))
	 max = l;
	if((r <= nheap)&&(dist[r] <= dist[max]))
	 max = r;
	if( max != i){
		swap(dist[i],dist[max]);
		swap(distances[i],distances[max]);
		min_heapify(max);
	}
}

void decrease_key(int ind,int key){
	dist[ind] = key;
		//dist[ind] = key;
		while(ind>1 && dist[ind]<dist[ind/2]){
			swap(dist[ind],dist[ind/2]);
			swap(distances[ind],distances[ind/2]);
			ind = ind/2;
		}
}

void Djikstra(){
	
	int u=0,k;//,nh=nheap;
	//dist[start]=0;
	//distances[start]=0;
	decrease_key(start,0);
	while(nheap >= 0){
		
		min_heapify(1);

		u = distances[1];
		swap(dist[1],dist[nheap]);
		swap(distances[1],distances[nheap]);
		nheap--;
		
		k = adjlist[u].size();
		for(int i=0;i<k;i++){
			
			if((dist[adjlist[u][i]] > (dist[u]+wts[u][i]))){
				
				decrease_key(adjlist[u][i],(dist[u]+wts[u][i]));
			}
		}		
	}
}

//		10 1 4 315 567 647 270 15 35 1000
//		08 2 5 446 192 703 336 56 75 1000

int main(){
	int w_1,w_2,w_3,c_1,c_2,d_1,d_2,d;
	
	scanf("%d %d %d %d %d %d %d %d %d %d",&n,&start,&d,&c_1,&c_2,&d_1,&d_2,&w_1,&w_2,&w_3);
	//start--;
	nheap = n;
	
	wts.resize(n+1);
	dist.resize(n+1);
	vis.resize(n+1);
	distances.resize(n+1);
	adjlist.resize(n+1);
	
	for(int i=1;i<=n;i++){
		vis[i] = i;
		dist[i]=214748364;
		distances[i] = i;
	}

	int deg,vertex;
	for(int i=1;i<=n;i++){
		deg = (i*c_2 + i*i*d_2)%d;

		for(int j=1;j<=deg;j++){
			vertex = 1 + (i*c_1 + j*d_1)%n;
			//if(vertex != i){
				adjlist[i].push_back(vertex);
				vertex = (i*w_1 + j*w_2)%w_3;
				wts[i].push_back(vertex);
			//}
		}
	}

//	
//for(int i=1;i<=n;i++){
//	int k = adjlist[i].size();
//	for(int j=0;j<k;j++){
//		printf("%d %d ",adjlist[i][j],wts[i][j]);
//		}
//	printf("\n");
//}

	Djikstra();
	
	for(int i=1;i<=n;i++){
		printf("%d ",i);
		if(dist[i] == 214748364)
		printf("%d\n",-1);
		else
		printf("%d\n",dist[i]);
	}
	

	
	return 0;
}
