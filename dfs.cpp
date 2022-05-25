#include<bits/stdc++.h>
using namespace std;

class Graph{
	public:
		int V;
		vector<list<int> > adj;
		vector<bool> visited;
		Graph(int v){
			V=v;
			adj.resize(v);
			visited.resize(v,false);
		}
		void addedge(int x,int y);
		void dfs(int s);
};

void Graph::addedge(int x, int y){
	adj[x].push_back(y);
}
void Graph::dfs(int s){
	
	cout<<s<<" ";
	visited[s]=true;
	list<int>::iterator i;
	for(i=adj[s].begin();i!=adj[s].end();++i){
		if(!visited[*i]){
			dfs(*i);
		}
	}
	
	
}


int main(){
	Graph g(4);
	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(1,2);
	g.addedge(2,0);
	g.addedge(2,3);
	g.addedge(3,3);
	g.dfs(2);
	
}
