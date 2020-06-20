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


};
int dfs(vector<vector<int>> list,int *vis,int src,int &ma){
  vis[src] = 1;
    for(auto node:list[src]){
      ma = max(node,ma);
      if (vis[node]==0){
      dfs(list,vis,node,ma);
      }
    }
    return ma;
}

int main(){

  int n;//number of vertices
  int m;
  cin>>n>>m;

  vector<vector<int>> list;
  list.resize(n+1);
  int vis[n+1]={};
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    list[a].pb(b);
    list[b].pb(a);
  }
  int maxi=0;
  int count=0;
  for(int i=1;i<=n;i++){
    if(!vis[i]){

      if(i<maxi)
      count++;
       maxi = dfs(list,vis,i,maxi);


    }
  }
  cout<<count;

}
