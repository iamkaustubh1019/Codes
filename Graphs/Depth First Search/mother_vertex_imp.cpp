#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define vvi vector<vector<int>>

void dfs(vvi list,int src,int *visited){

    for(auto &node:list[src]){
        if(visited[node]==0){
        visited[node]=1;
        dfs(list,node,visited);
      }
    }

  }


int main(){

  int n;
  int m;
  cin>>n>>m;
  vvi list;
  list.resize(n+1);

  for (int i=0;i<m;i++)
     {
       int a,b;
       cin>>a>>b;
       list[a].pb(b);

     }
  int visited[n+1]={};
  int mother_vertex;

  for(int i=1;i<=n;i++){
    if(visited[i]==0){
      dfs(list,i,visited);
      mother_vertex = i;
    }
  }

  cout<<mother_vertex<<" happy ";





}
