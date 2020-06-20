#include<bits/stdc++.h>
using namespace std;

void n_connected (vector<int> list[],int *visited,int n,queue<int> q){

    while(!q.empty()){

              int size = list[q.front()].size();

              for(int i=0;i<size;i++){
                  if(visited[list[q.front()][i]]!=1){
                    q.push(list[q.front()][i]);
                    visited[list[q.front()][i]]=1;
                   // count++;
                  }

              }

              q.pop();


          }
      }

int main()
 {
     int n,m,k;
     cin>>n>>m>>k;
     vector<int> list[n+1];
     for(int i=0;i<m;i++)
     {   int a,b;
          cin>>a>>b;
         list[a].push_back(b);
         list[b].push_back(a);

     }

     int visited[n+1];

      for(int i=0;i<n+1;i++)
      visited[i]=0;

      int n_conn=0;



          queue<int> q;
          for(int i=1;i<=n;i++)
          {
              if (visited[i]==0)
              {
                  n_conn++;
                  visited[i]=1;
                  q.push(i);
                  n_connected(list,visited,n,q);


              }
          }

      cout<<n_conn<<"\n";






     if(n_conn>k)
     cout<<"-1";

     else if(m-n+k>=0)
      cout<<-n+m+k;
      else
      cout<<m-k;

 }
