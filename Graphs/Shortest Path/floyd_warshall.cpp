#include<bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<int> mat[],int n){


  for(int k =0; k < n; k++){
      for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
              mat[i][j] = min( mat[i][j], mat[i][k] + mat[k][j] );
          }
      }
  }

  for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if (mat[i][j]!=1000000)
          cout<<mat[i][j]<<" ";
        else
        cout<<"INF ";
      }
      cout<<"\n";
  }


}

int main(){
  int t;
  cin>>t;
  while(t--){
  int n;
  cin>>n;

  vector<int> mat[n];
  // mat.resize(n+1);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    string a;
    cin>>a;

    if(a=="INF")
    mat[i].push_back(1000000);

    else

    mat[i].push_back(stoi(a));
      }
    }





  floyd_warshall(mat,n);

}
}
