#include<bits/stdc++.h>
 using namespace std;
 //greedy algorithm


	unordered_set<int>  uset[100001];



 void dfs(int src,int n,int *vis){
 	vis[src]=1;

 	for(int i=1;i<=n;i++){
 		if(uset[src].find(i)==uset[src].end() && !vis[i]){
 			dfs(i,n,vis);
 		}
 	}
 }

 int32_t main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


 	int n;
 	int m;
 	cin>>n>>m;
 


 	





 	for(int i=0;i<m;i++){

 		int a,b;

 		cin>>a>>b;

 		uset[a].insert(b);
 		uset[b].insert(a);
 	}

 	int count=0;
 	int vis[n+1]={};
 	for(int i=1;i<=n;i++){
 		if(!vis[i]){
 			dfs(i,n,vis);
 			count++;
 		}
 	}
 	cout<<count-1;

 	// 


 	// cout<<cost<<"\n";
 }