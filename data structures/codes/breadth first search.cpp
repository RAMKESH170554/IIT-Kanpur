#include<stdio.h>
// visited = 1, unvisited = 0

struct A{
	int x,y;	
};
int n,m[1000][1000] = {0}; //dist[1000][1000] = {0};
int h = 1, t = 1, nelem = 0,counter = 0;
int visit[1000][1000] = {0};
struct A Q[1000];

void enq(int i, int j){
	//if(h==1 && t==1){
		Q[t].x = i;
		Q[t].y = j;
		t++;nelem++;
}

void deq(){
//	printf("%d %d %d\n",Q[h].x,Q[h].y,dist[Q[h].x][Q[h].y]);
	h++;nelem--;
}

void BFS(){
	int row[] = {0,-1,0,0,1};
	int col[] = {0,0,1,-1,0};
	int i = 1, j = 1;
	enq(i,j);
	//dist[1][1] = 0;
	visit[1][1] = 1;
	while(nelem){
		
		if(Q[h].x == n && Q[h].y == n){
			printf("%d %d",m[i][j]-1,counter);x
			break;
		}
		
		for(int k =1;k<=4; k++){
			int r = i+row[k];
			int c = j+col[k];
			if(m[r][c]  && !visit[r][c]){
				visit[r][c] = 1;
				enq(r,c);
				m[r][c] = m[i][j] + 1;
				//dist[r][c] = dist[i][j] + m[r][c];
			}
		}

		deq();
		i = Q[h].x;
		j = Q[h].y;
counter++;
		}
	if(nelem == 0)
		printf("no shortest path");
//	else{
//		while(i!=1 && j!=1){
//			int rows,cols,max = 0;
//			for(int k =1;k<=4; k++){
//				int r = i+row[k];
//				int c = j+col[k];
//				if(max < m[r][c] && m[r][c]){
//					max = m[r][c];
//					rows = r,cols = c;
//				}
//			}
//			//printf("\n%d %d",rows,cols);
//			i = rows,j = cols;	
//		}
//	}
}

/*
5
1 1 0 1 1
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
1 0 1 1 1

5
1 0 1 1 1
1 0 1 0 1
1 1 1 0 1
0 0 0 0 1
1 1 1 0 1
*/
 int main(){
 	scanf("%d",&n);
 	for(int i =1;i<= n;i++)
 		for(int j = 1;j<= n;j++)
 			scanf("%d",&m[i][j]);
	BFS();
//	for(int i =1;i<= n;i++)
// 		for(int j = 1;j<= n;j++)
// 			printf(" %d ",dist[i][j]);
	return 0; 
 }
