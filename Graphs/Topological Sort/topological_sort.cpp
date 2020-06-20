#include<bits/stdc++.h>
using namespace std;


void dfs(set<int,greater<int>> list[],int *vis,int src,stack<int> &s ){
	vis[src]=1;

	for(auto node:list[src]){
		if(!vis[node])

			dfs(list,vis,node,s);
	}


	s.push(src);


}



int main(){

	int n;
	int m;

	cin>>n>>m;

	set<int,greater<int>> list[n+1];

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		list[a].insert(b);
	}

	int vis[n+1]={};

	stack<int> s;


	for(int i=n;i>0;i--){

		if(!vis[i]){
			dfs(list,vis,i,s);
		}
	}


	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}



}