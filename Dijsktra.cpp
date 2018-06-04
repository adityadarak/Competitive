#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adj;
    vector<vector<int>> G;
    
    public:
    Graph(int V);
    void addedge(int a, int b, int w);
    void Djisktra(int u);
    int findmin(bool sptset[], int dist[]);
};

Graph::Graph(int V){
    this->V=V;
    adj=new list<int>[V];
    G.resize(V);
    for(int i=0;i<V;i++){
        G[i].resize(V);
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            G[i][j]=0;
        }
    }
}

void Graph::addedge(int a,int b, int w){
    adj[a].push_back(b);
    adj[b].push_back(a);
    G[a][b]=w;
    G[b][a]=w;
}

int Graph::findmin(bool sptset[], int dist[]){
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<V;i++){
        if(!sptset[i] && dist[i]<=min){
            min_index=i;
            min=dist[i];
        }
    }
    return min_index;
}

void Graph::Djisktra(int v){
    bool sptset[V];
    int dist[V];
    
    
    for(int i=0;i<V;i++){
        sptset[i]=false;
        dist[i]=INT_MAX;
    }
    
    dist[v]=0;
    for(int i=0;i<V-1;i++){
        int u=findmin(sptset,dist);
        sptset[u]=true;
        for(int j=0;j<V;j++){
            if(!sptset[j] && dist[u]!=INT_MAX && G[u][j]!=0 && (dist[u]+G[u][j]<dist[j])){
                dist[j]=dist[u]+G[u][j];
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main() {
	// your code goes here\

	Graph g(5);
	g.addedge(0,1,5);
	g.addedge(1,3,5);
	g.addedge(0,2,4);
	g.addedge(2,4,12);
	g.addedge(3,4,4);
	g.Djisktra(0);
	return 0;
}
