
#include<bits/stdc++.h>
#include<queue>
using namespace std;
# define INF 1000000007

class Graph
{
    int V; 
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

void Graph::shortestPath(int src)
{
    set< pair<int, int> > setds;
	
    vector<int> dist(V, INF);

    setds.insert(make_pair(0, src));
    dist[src] = 0;

    while (!setds.empty())
    {

        pair<int, int> temp = *(setds.begin());
        setds.erase(setds.begin());

        int u = temp.second;

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {

            int v = (*i).first;
            int weight = (*i).second;
 
            //  If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; ++i)
    	if(dist[i] == INF)
    	printf("%d -1\n",i);
    	else
        printf("%d %d\n", i, dist[i]);
}

int main()
{
    int w_1,w_2,w_3,c_1,c_2,d_1,d_2,d,V,start;
	
	scanf("%d %d %d %d %d %d %d %d %d %d",&V,&start,&d,&c_1,&c_2,&d_1,&d_2,&w_1,&w_2,&w_3);
    Graph g(V);
 
 	int deg,vertex,ver;
	for(int i=1;i<=V;i++){
		deg = (i*c_2 + i*i*d_2)%d;

		for(int j=1;j<=deg;j++){
			ver = (i*c_1 + j*d_1)%V;
			//if(vertex != i){
				vertex = (i*w_1 + j*w_2)%w_3;
				g.addEdge(i-1, ver , vertex);
			//}
		}
	}

    g.shortestPath(start-1);
 
    return 0;
}
