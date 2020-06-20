#include<bits/stdc++.h>

using namespace std;


struct compare{
bool operator()(const pair<int,int> p1,const pair<int,int> p2){
  if(p1.second>p2.second)
  return true;
  return false;

}
};

typedef pair<int,int> pairs;

int main(){
  int n;
  cin>>n;
  int mat[n+1][n+1]={};//adj matrix
  int m;
  cin>>m; //number of edges
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    mat[a][b] =c;
    mat[b][a] =c;
  }
  int dis[n+1]={};
  for (int i=0;i<n+1;i++){
    dis[i]=INT_MAX;
  }
  for(int i=0;i<n+1;i++)
  cout<<dis[i]<<" ";
  cout<<"Done\n";
  int src;
  cin>>src;
    cout<<"Done\n";

  priority_queue<pairs,vector<pairs>,compare> q;

  int vis[n+1]={};
  dis[src]=0;


  q.push(make_pair(src,dis[src]));


  while(!q.empty()){

    pairs curr_src = q.top();
    if(vis[curr_src.first])
    {
      q.pop();
      continue;
    }
    if(!q.empty())
    q.pop();
    cout<<"Current Source and its distance: ";
    cout<<" "<<curr_src.first<<" "<<curr_src.second;
    vis[curr_src.first]=1;
      for(int i=0;i<n+1;i++){
      if(vis[i]!=1 && mat[curr_src.first][i]!=0){

        dis[i] = min(dis[i],dis[curr_src.first]+mat[curr_src.first][i]);
        q.push(make_pair(i,dis[i]));

      }
    }
    cout<<endl;

  }
  cout<<endl;


  for(int i=0;i<n+1;i++){
    cout<<"Distance of node "<<i<<" from source " <<src<<" is "<<dis[i]<<endl;
  }






}
