/*
Find Shortest distance from a guard in a Bank
Given a matrix that is filled with ‘O’, ‘G’, and ‘W’ where ‘O’ represents open space,
‘G’ represents guards and ‘W’ represents walls in a Bank. Replace all of the O’s in
the matrix with their shortest distance from a guard, without being able to go through
any walls. Also, replace the guards with 0 and walls with -1 in output matrix.

Expected Time complexity is O(MN) for a M x N matrix.

O ==> Open Space
G ==> Guard
W ==> Wall

Input:
  O  O  O  O  G
  O  W  W  O  O
  O  O  O  W  O
  G  W  W  W  O
  O  O  O  O  G

Output:
  3  3  2  1  0
  2 -1 -1  2  1
  1  2  3 -1  2
  0 -1 -1 -1  1
  1  2  2  1  0

  */


  #include<bits/stdc++.h>

  using namespace std;
  typedef pair<pair<int,int>,int> pairs;

  struct compare{
    bool operator()(pairs p1,pairs p2){
      return p1.second>p2.second;

    }
  };




  int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<int> mat[n];
    // mat.resize(n);
    // vector<pair<int,int>> pairs;
    int size=0;
    priority_queue<pairs> q;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        char a;
        cin>>a;
        if(a=='0')
        mat[i].push_back(1000000);
        else if(a=='G'){
          // cout<<i<<" "<<j<<" "<<endl;
          q.push({{i,j},0});
          mat[i].push_back(0);
          size++;
      }
        else
        mat[i].push_back(-1);
      }
    }



    while(!q.empty()){

      pairs p = q.top();

      int i = p.first.first;
      int j = p.first.second;
      int dis = p.second;




      if(p.second>mat[i][j]){
        // cout<<"once "<<i<<" "<<j<<" "<<p.second<<" "<<mat[i][j] ;

        q.pop();
        continue;
      }

      // cout<<i<<" "<<j<<" "<<p.second<<endl;
      q.pop();

      if(i<n-1 && j<n-1){
        if(mat[i+1][j]>dis+1)

            {
              mat[i+1][j]=dis+1;
              q.push({{i+1,j},dis+1});

            }

            if(mat[i][j+1]>dis+1)
            {


               mat[i][j+1]=dis+1;
               q.push({{i,j+1},dis+1});


            }
        }
      else if (i<n-1){
        if(mat[i+1][j]>dis+1)
            {
              mat[i+1][j]=dis+1;
              q.push({{i+1,j},dis+1});

            }

      }

      else{
        if(mat[i][j+1]>dis+1)
        {

           mat[i][j+1]=dis+1;
           q.push({{i,j+1},dis+1});

        }

      }
      if(i>0 && j>0){
        if(mat[i-1][j]>dis+1)

            {
              mat[i-1][j]=dis+1;
              q.push({{i-1,j},dis+1});

            }

            if(mat[i][j-1]>dis+1)
            {
               mat[i][j-1]=dis+1;
               q.push({{i,j-1},dis+1});

            }

      }
      else if (i>0){
        if(mat[i-1][j]>dis+1)
            {
              mat[i-1][j]=dis+1;
              q.push({{i-1,j},dis+1});

            }

      }

      else{
        if(mat[i][j-1]>dis+1)
        {

           mat[i][j-1]=dis+1;
           q.push({{i,j-1},dis+1});

        }

    }
  }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cout<<mat[i][j]<<" ";
      }
      cout<<'\n';
    }


  }
