#include<bits/stdc++.h>
using namespace std;

int fib(int *a,int query){


  for(int i=2;i<=query;i++)
  a[i]=a[i-1]+a[i-2];

   return a[query];
}




int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[1000001];
    for(int i=0;i<1000001;i++)
    a[i]=0;
    a[1]=1;



      int query;
      cin>>query;

      int ans = fib(a,query);
      cout<<"\n"<<ans;


}
