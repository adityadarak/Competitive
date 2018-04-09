#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

	public:
	Graph(int V);
	void addEdge(int v,int w);
	bool isCyclic();	
};

Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}

void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}

bool Graph::isCyclic(){
	bool *visited=new bool[V];
	for(int i=0;i<V;i++){
		visited[i]=false;
	}
	int s=0;
	list<int>::iterator i;
	for(i=adj[s].begin();i!=adj[s].end();i++){
		//Complete This
	}
}

int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
	return 0;
}