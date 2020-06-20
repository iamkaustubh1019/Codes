#include<bits/stdc++.h>
using namespace std;

int main(){

  int n,m;
  cin>>n>>m;

  int a[n+1][n+1];

  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){
        a[i][j]=0;
    }
  }

  for(int i=0;i<m;i++){
    int c,b;

    cin>>c>>b;

    a[c][b]=1;
    a[b][c]=1;
  }
  int q;
  cin>>q;
  while(q--){
    int b,c;
    cin>>b>>c;
    if (a[b][c]==1 || a[b][c]==1)
    cout<<"YES\n";
    else cout<<"NO\n";


  }

  return 0;



}
