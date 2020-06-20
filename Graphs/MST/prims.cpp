#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pairs;

struct compare{
	bool operator()(pairs p1,pairs p2){
		if(p1.second.second==p2.second.second)
			return p1.first<p2.first;
		else return p1.second.second<p2.second.second;
	}
}
//greedy algorithm




int32_t main(){



	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	int n;
	int m;
	cin>>n>>m;

	vector<pairs> list[n+1];

	for(int i=0;i<m;i++){
		int a,b,weight;

		cin>>a>>b>>weight;

		list[a].push_back({b,weight});
		list[b].push_back({a,weight});
	}


	int vis[n+1]={};

	priority_queue<pairs, vector<pairs> , compare> q;


	q.push({0,1});
	int c=0;

	while(!q.empty()){

		pairs p =q.top();

		q.pop();

		int src  = p.second;
		int cost = p.first;

	


		if(vis[src])
			continue;
		vis[src]=1;
		c+=cost;


		for(auto node:list[src]){

			if(!vis[node.first]){
				q.push({node.second+cost,node.first});
			}
		}
	}

	cout<<c<<"\n";








}