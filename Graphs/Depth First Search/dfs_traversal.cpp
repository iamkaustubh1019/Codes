#include<bits/stdc++.h>
using namespace std;
#define pb push_back

struct Edge{
  int src;
  int dest;
};

class Graph{

public:

        vector<vector<int>> list;

        Graph(std::vector<Edge>const &edges,int n)
        {
          list.resize(n+1);

          for(auto &edge:edges){

            list[edge.src].pb(edge.dest);
            list[edge.dest].pb(edge.src);

          }
        }

        void DFS(int src,int n){

        }
};


int main(){

  int n;//number of vertices
  int m;//number of edges;
  cin>>n>>m;
  std::vector<Edge> edges;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    edges.pb({a,b});
  }

  Graph graph(edges,n);

    graph.DFS(1,n);

}
