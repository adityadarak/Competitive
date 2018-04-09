#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

	public:
	Graph(int V);
	void addEdge(int v,int w);
	void DFS(int s);
	void DFSimp(int s ,bool visited[]);	
};

Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}

void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}

void Graph::DFSimp(int s, bool visited[]){
	list<int>::iterator i;
	visited[s]=true;
	cout<<s<<" ";
	for(i=adj[s].begin();i!=adj[s].end();i++){
		if(!visited[*i]){
			visited[*i]=true;
			DFSimp(*i,visited);
		}
	}
}

void Graph::DFS(int s){
	cout<<"DFS of the graph starting from vertex "<<s<<" is:"<<endl;
	bool *visited=new bool[V];
	for(int i=0;i<V;i++){
		visited[i]=false;
	}
	DFSimp(s,visited);
	cout<<endl;
}

int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
}