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
		int temp = dist[max];
		dist[max] = dist[i];
		dist[i] = temp;
		min_heapify(max);
	}
}

void decrease_key(int ind,int key){
	dist[ind] = key;
	if(distances[ind]>key){
		//dist[ind] = key;
		while(ind>1 && dist[ind]<dist[ind/2]){
			swap(dist[ind],dist[ind/2]);
			ind = ind/2;
		}
	}
}

void Djikstra(){
	
	int u=0,k,nh=nheap;
	//dist[start]=0;
	distances[start]=0;
	decrease_key(start,0);
	while(nh >= 0){
		
		min_heapify(1);

		vector<int >::iterator locate = find(distances.begin()+1, distances.begin()+n, dist[1]);
		u = locate - distances.begin();

//		swap(dist[1],dist[nheap]);
//		nheap--;
		nh--;
		dist[1] = 214748364;
		
		k = adjlist[u].size();
		for(int i=0;i<k;i++){
			
			if((distances[adjlist[u][i]] > (distances[u]+wts[u][i]))){
				decrease_key(adjlist[u][i],(distances[u]+wts[u][i]));
				distances[adjlist[u][i]] = (distances[u]+wts[u][i]);
			}
		}		
	}
}

//		10 1 4 315 567 647 270 15 35 1000
//		08 2 5 446 192 703 336 56 75 1000

int main(){
	int w_1,w_2,w_3,c_1,c_2,d_1,d_2,d,x,w;
	
	scanf("%d %d %d %d %d %d %d %d %d %d",&n,&start,&d,&c_1,&c_2,&d_1,&d_2,&w_1,&w_2,&w_3);
	//start--;
	//scanf("%d %d",&n,&start);

	nheap = n;
	
	wts.resize(n+1);
	dist.resize(n+1);
	vis.resize(n+1);
	distances.resize(n+1);
	adjlist.resize(n+1);
	
	for(int i=1;i<=n;i++){
		vis[i] = 0;
		dist[i]=214748364;
		distances[i] = 214748364;
	}

	int deg,vertex;
	for(int i=1;i<=n;i++){
		deg = (i*c_2 + i*i*d_2)%d;

		for(int j=1;j<=deg;j++){
			vertex = 1 + (i*c_1 + j*d_1)%n;
			if(vertex != i){
				adjlist[i].push_back(vertex);
				vertex = (i*w_1 + j*w_2)%w_3;
				wts[i].push_back(vertex);
			}
		}
	}

/*

*/
//	for(int i=1;i<=n;i++){
//		scanf("%d",&x);
//		while(x!=-1){
//			scanf("%d",&w);
//			adjlist[i].push_back(x);
//			wts[i].push_back(w);
//			scanf("%d",&x);
//		}
//	}

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
		if(distances[i] == 214748364)
		printf("%d\n",-1);
		else
		printf("%d\n",distances[i]);
	}
	

	
	return 0;
}
