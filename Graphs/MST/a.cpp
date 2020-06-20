#include<bits/stdc++.h>
 using namespace std;

 int32_t main(){

ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 




 	int n;
 	int m;
 	cin>>n;
 	m = n-1;

 	vector<int> list[n+1];

 	for(int i=0;i<m;i++){
 		int a;
 		int b;
 		cin>>a>>b;

 		list[a].push_back(b);
 		list[b].push_back(a);

 	}

 	queue<int> q;
 	int ans[n+1];
 	int visited[n+1]={};
 	bool flag=true;

 	for(int i=0;i<n;i++){
 		cin>>ans[i+1];
 		visited[ans[i+1]]++;
 		if(visited[ans[i+1]]>1)
 			flag=false;
 		// cout<<vis[ans[i+1]]<<" ";
 	}



 	if(flag){


 	q.push(ans[1]);
 	int vis[n+1]={};
 	vis[ans[1]]=1;

 	while(!q.empty()){
 		int src=q.front();
 		q.pop();

 		for(auto node:list[src]){
 			if(vis[node]==0){
 				q.push(node);
 				vis[node]=vis[src]+1;
 			}
 		}
 	}


 	
 	


 	for(int i=2;i<=n;i++){
 		if(vis[ans[i]]==vis[ans[i-1]])
 			continue;
 		if(vis[ans[i]]<vis[ans[i-1]]){
 			cout<<"No\n";
 			flag=false;
 			break;

 		}
 	}

 	if(flag)
 		cout<<"Yes\n";

 }

 else{
 	cout<<"No\n";
 }



 }