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

        Graph(vector<Edge>const &edges,int n){

          list.resize(n);

          for(auto &edge:edges){

            list[edge.src].pb(edge.dest);
            list[edge.dest].pb(edge.src);
          }

        }

        void BFS_(int source){
          int n = this->list.size();
          int visited[n+1];
          queue<int> s;


          s.push(source);
          cout<<source<<" ";


          while(!s.empty()){

            for(auto &node:this->list[s.front()]){
              if (visited[node]!=1)
               {
                 s.push(node);
                 cout<<node<<" ";
                 visited[node]=1;
               }
            }
            s.pop();

          }
        }
};

void BFS(Graph g,int n,int source){
    int visited[n+1];
    visited[source]=1;
    queue<int> q;


    q.push(source);
    cout<<source<<" ";
    vector<vector<int>> v = g.list;
    cout<<"\n";
    while(!q.empty()){
      // cout<<s.top<

      for(auto &node:v[q.front()]){
        if (visited[node]!=1)
         {
           q.push(node);
           cout<<node<<" ";
           visited[node]=1;
         }
      }
      cout<<"\n";
      q.pop();

    }
  }

int main(){
  int n,m;
  cin>>n>>m;

  vector<Edge> edges;

  for(int i=0;i<m;i++){

    int a,b;
    cin>>a>>b;
    Edge e = {a,b};

    edges.pb(e);
  }

  Graph g(edges,n);

  BFS(g,n,1);
  cout<<" ";
  g.BFS_(2);
  cout<<" ";
  for(int i=0;i<g.list[1].size();i++)
  cout<<g.list[1][i]<<" ";







}
