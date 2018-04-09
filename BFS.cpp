#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

	public:
	void addEdge(int v,int w);
	Graph(int V);
	void BFS(int s);	
};

Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::BFS(int s){
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	list<int> queue;

	queue.push_back(s);
	visited[s]=true;
	cout<<"BFS Starting from vertex "<<s<<" is:"<<endl;
	while(!queue.empty()){
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(list<int>::iterator i=adj[s].begin();i!=adj[s].end();i++){
			if(!visited[*i]){
				visited[*i]=true;
				queue.push_back(*i);
			}
		}
	}
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
 
    g.BFS(2);
	return 0;
}