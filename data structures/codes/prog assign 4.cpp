#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node {
    long long int v;
    long long int w;
    struct Node * next;
} node;

long long int pos[100000];

node *addnode(node *head, long long int i, long long int j){
    node *cur;
    cur=(node*)malloc(sizeof(node));
    cur->v=i;
    cur->w=j;
    cur->next=head;
    head=cur;
    return head;
}

void Min_Heapify(long long int arr[], long long int ind[], long long int n, long long int i){
    long long int l=2*i+1, r=2*(i+1), min=i;
    if(l<n && arr[ind[l]]<arr[ind[min]]) min=l;
    if(r<n && arr[ind[r]]<arr[ind[min]]) min=r;
    if(min!=i){
        long long int tem=ind[i];
        pos[ind[i]]=min;
        pos[ind[min]]=i;
        ind[i]=ind[min];
        ind[min]=tem;
        Min_Heapify(arr, ind, n, min);
    }
    return;
}



long long int Extract_Min(long long int arr[],long long int ind[], long long int n){
    long long int min=arr[0], mini=ind[0];
    pos[ind[0]]=n-1;
    pos[ind[n-1]]=0;
    ind[0]=ind[n-1];
    ind[n-1]=mini;
    Min_Heapify(arr, ind, n-1, 0);
    return mini;
}

int main() {
    long long int n, s, D, C_1, C_2, D_1, D_2, W_1, W_2, W_3;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",&n, &s, &D, &C_1, &C_2, &D_1, &D_2, &W_1, &W_2, &W_3);
    node **adjlist;
    adjlist=(node**)malloc(n*sizeof(node *));
    for(long long int i=0; i<n; i++){
        adjlist[i]=NULL; pos[i]=i;
    }
    
    for(long long int i=1; i<=n; i++){
        long long int deg = (  i*C_2 + i*i*D_2  ) % D;
        for(long long int j=1; j<=deg; j++){
            long long int temp_node_vertex = ( i*C_1 + j*D_1 ) % n;
		    //temp_node_vertex += 1;
		    long long int temp_node_weight = ( i*W_1 + j*W_2 ) % W_3;		//Weight of edge ( i, temp_node.vertex)
		    //node *no=makenode(temp_node_vertex, temp_node_weight);
		    adjlist[i-1]=addnode(adjlist[i-1], temp_node_vertex, temp_node_weight);
        }
    }
    long long int dist[n], ind[n];
    for(long long int i=0; i<n; i++){
        dist[i]=LLONG_MAX;
        ind[i]=i;
    }
    long long int y=0;
    dist[s-1]=0; long long int N=n-y;
    for(long long int j=(N-2)/2; j>=0; j--){
        Min_Heapify(dist,ind,N-1,j);
    }
    for(long long int i=0; i<N; i++){
        long long int curv=Extract_Min(dist, ind, N-i);
        node *cur=adjlist[curv];
        while(cur!=NULL){
            if(dist[curv]!=LLONG_MAX && dist[cur->v] > dist[curv] + cur->w){
                dist[cur->v] = dist[curv] + cur->w;
                long long int x=pos[cur->v];
                while(x && dist[ind[x]]<dist[ind[(x-1)/2]]){
                    long long int te=ind[x];
                    pos[ind[x]]=(x-1)/2;
                    pos[ind[(x-1)/2]]=x;
                    ind[x]=ind[(x-1)/2];
                    ind[(x-1)/2]=te;
                    x=(x-1)/2;
                }
            }
            cur=cur->next;
        }
        
    }
    for(long long int i=0; i<n; i++){
        if(dist[i]==LLONG_MAX) dist[i]=-1;
    }
    for(long long int i=0; i<n; i++){
        printf("%lld %lld\n", i+1, dist[i]);
    }
    
}

