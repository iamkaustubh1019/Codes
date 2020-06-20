#include<bits/stdc++.h>
using namespace std;

int fib(int *a,int query){

  // cout<<query<<" ";

  if (query==0 || query==1)

  return 1;

   //this is where we use our stored values.if you comment the next two lines every element of tree would be visited.
   if (a[query]!=0 && query>1)

   return a[query];

   cout<<query<<" ";

   a[query] = fib(a,query-1)+fib(a,query-2);

   return a[query];
}
/* commenting the above two lines gives
o(n^2)
10 9 8 7 6 5 4 3 2 2 3 2 4 3 2 2 5 4 3 2 2 3 2 6 5 4 3 2 2 3
2 4 3 2 2 7 6 5 4 3 2 2 3 2 4 3 2 2 5 4 3 2 2 3 2 8 7 6
5 4 3 2 2 3 2 4 3 2 2 5 4 3 2 2 3 2 6 5 4 3 2 2 3 2 4 3 2 2
and when we use it as defined
10 9 8 7 6 5 4 3 2
o(n)

Explanation is quite clear bitch.


*/


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
