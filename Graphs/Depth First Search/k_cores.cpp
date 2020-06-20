#include<bits/stdc++.h>

using namespace std;

#define k 3

bool dfs(int *degree,vector<vector<int>>const list,int *vis,int source){

  vis[source] =1;

  for(auto node:list[source]){
    if(degree[source]<k)
     degree[node]--;
    if(vis[node]==0){

      if(dfs(degree,list,vis,node)==false)
      {

        degree[source]--;
      }
    }
  }
  return degree[source]>=k;

}
int main(){
  int n;
  int m;
  cin>>n>>m;

  vector<vector<int>> list;
    list.resize(n+1);
    int degree[n+1]={};
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      degree[a]++;
      degree[b]++;
      list[a].push_back(b);
      list[b].push_back(a);

  }

    int vis[n+1]={};


    if(dfs(degree,list,vis,2))
      for(int i=0;i<n+1;i++){
        if(degree[i]>=k)
        cout<<i<<" ";
      }
    }

    else{
      cout<<"NO";
    }




}
