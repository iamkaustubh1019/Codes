#include<bits/stdc++.h>
using namespace std;
#define pb push_back

struct Edge{
  int src;
  int dest;
};

class Graph{

public:

        unordered_map<int,vector<int>> list;

        Graph(std::vector<Edge>const &edges,int n)
        {
          // list.resize(n+1);

          for(auto &edge:edges){

            // if(list.find(edge.src)==)

            list[edge.src].pb(edge.dest);
            list[edge.dest].pb(edge.src);

          }
        }

        void DFS(int src,unordered_map<int,int> &vis){
          cout<<src<<" ";
          vis[src]=1;

          for(auto node:list[src])

            {
              // cout<<node<<" ";
              if(vis[node]==0){
                DFS(node,vis);
              }
            }



        }
};


int main(){

  int n;//number of vertices
  // int m;//number of edges;
  cin>>n;
  std::vector<Edge> edges;
  int src;
  unordered_map<int,int> vis;
  unordered_map<int,int> s;


  for(int i=0;i<n;i++){
    int a,b;

    cin>>a>>b;
      src=a;
      if(s.find(a)==s.end())
      {s[a]=1;}
      else
      s[a]++;
      if(s.find(b)==s.end())
      s[b]=1;
      else
      s[b]++;

    vis[a]=0;
    vis[b]=0;
    edges.pb({a,b});
  }

  Graph graph(edges,n);
  for(auto node:s)
  if (node.second%2==1)
  {
    src=node.first;
    break;
  }
  // unordered_map<int,int> vis;

    graph.DFS(src,vis);

}
