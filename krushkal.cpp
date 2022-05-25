#include<bits/stdc++.h>
using namespace std;
class dsu{
    public:
        int* parent;
        int* rank;
        dsu(int n){
            parent = new int[n];
            rank = new int[n];
            for(int i=0;i<n;i++){
                parent[i]=-1;
                rank[i]=1;
            }
            
        }
        int find(int x){
            if(parent[x]==-1){ 
                return x;
                
            }
            return find(parent[x]);
        }
        void unite(int x, int y){
            int p1 = find(x);
            int p2 = find(y);
            if(rank[p1]<rank[p2]){
                rank[p2]+=rank[p1];
                parent[p1]=p2;
            }else{
                rank[p1]+=rank[p2];
                parent[p2]=p1;
            }
        }
};

class Graph{
    public:
        int V=6;
        vector<vector<int> >edge;
        Graph(int v){
            V=v;
        }
        void addedge(int x,int y,int w){
            edge.push_back({w,x,y});
        }
        void krushkals();
};

void Graph::krushkals(){
    sort(edge.begin(),edge.end());
    int tw=0;
    dsu s(V);
    for(auto e:edge){
        int w=e[0];
        int x=e[1];
        int y=e[2];
        if(s.find(x)!=s.find(y)){
            s.unite(x,y);
            tw+=w;
            cout<<x<<"-"<<y<<"->"<<w<<endl;
        }
    }
    cout<<"total weight of spanning tree:"<<tw;
}

int main(){
    Graph g(6);
    g.addedge(0,1,1);
    g.addedge(0,2,5);
    g.addedge(1,2,4);
    g.addedge(1,3,7);
    g.addedge(1,4,6);
    g.addedge(2,4,3);
    g.addedge(3,5,5);
    g.addedge(4,5,8);
    g.krushkals();
    
}
