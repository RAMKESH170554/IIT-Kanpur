#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    struct node *next;
    int vertex;
};
 
node *G[20];   
//heads of linked list
int visited[20],finish[20],disc[20],indeg[200]={0},flag[200]={0};
int time = 0;
int n;

void DFSexplore(int i){
	node *p;
	p = G[i];
	time = time +1;
	//printf("1 %d %d\n",i,visited[i]);
	//disc[i] = time;
	//printf("2 %d %d\n",i,disc[i]);
	visited[i]=1;
	//time++;
	//printf("%d\n",i);
	while(p != NULL)
    {
       i=p->vertex;
       
       if(visited[i] == 0)
            DFSexplore(i);
        p=p->next;
    }
	//time = time +1;
	//printf("3 %d %d\n",i,visited[i]);
	finish[i] = time;
	time = time+1;
	//printf("4 %d %d\n",i,finish[i]);
}

void DFS()
{	int i=0;
	for(i = 0;i<n;i++){
		if(visited[i] == 0){
		//	visited[i] = 1;
			DFSexplore(i);
		}
	}
    
}

void topological(){
	int count = 0,k,i,l;
	while(count < n){
		 for(k=0;k<n;k++){
            if((indeg[k]==0) && (flag[k]==0)){
                printf("%d ",k);
                flag [k]=1;
            }
 
            for(i=0;i<n;i++){
            	node *p;
				p=G[i];
       
        		while(p->next!=NULL){
        			p = p->next;
       		 		l = p->vertex;
        			if(l == k)
        				indeg[k]--;
				}
            }
        }
 
        count++;
	}
//	if(count != n)
//		printf("cycle");
}

// 7 5 -1 2 3 -1 3 -1 1 4 -1 1 -1 1 6 -1 0 -1
void insert_graph(int vi,int vj)
{
    node *p,*q;
    
    //acquire memory for the new node
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
 
    //insert the node in the linked list number vi
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        //go to end of the linked list
        p=G[vi];
       
        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}

void init_graph()
{
    int i,vj;
    //printf("Enter number of vertices:");
   
    scanf("%d",&n);
 
    //initialise G[] with a null
   
    for(i=0;i<n;i++)
    {
        G[i]=NULL;
        //read edges and insert them in G[]
        scanf("%d",&vj);
        while(vj >= 0){
        	indeg[vj] = indeg[vj]+1;
        	insert_graph(i,vj);
            scanf("%d",&vj);
        }
 		
    }
}

int main()
{
    init_graph();   
    for(int i=0;i<n;i++)
        visited[i]=0;
 	
 	//topological();
    DFSexplore(0);
//    // DFS(); both gives same result
    for(int i=0; i<n;i++)
    	printf("%d\n",finish[i]);
}
 

