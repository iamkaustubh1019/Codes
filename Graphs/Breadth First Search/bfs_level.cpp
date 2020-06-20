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

          list.resize(n+1);

          for(auto &edge:edges){

            list[edge.src].pb(edge.dest);
            list[edge.dest].pb(edge.src);
          }

        }
};

void BFS(Graph g,int n,int source,int level){
    int visited[n+1];
    for(int i=0;i<n+1;i++)
    visited[i]=0;
    visited[source]=1;
    int count =0;
    queue<int> q;
    q.push(source);
    vector<vector<int>> v = g.list;
    if (level==1)
    count=1;

    while(!q.empty()){

      for(auto &node:v[q.front()]){
        if (visited[node]==0)
         {
           q.push(node);

           visited[node]=visited[q.front()]+1;
           if (visited[node]==level){
             count++;
           }
         }
      }

      q.pop();

    }
    cout<<count;
  }

int main(){


  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin>>n;

  vector<Edge> edges;

  for(int i=0;i<n-1;i++){ //number of edge is n-1

    int a,b;
    cin>>a>>b;
    Edge e = {a,b};

    edges.pb(e);
  }

  Graph g(edges,n);
  int level;
  cin>>level;

  BFS(g,n,1,level); //prints the number of element at that level

return 0;
}
