#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pairs;

int main(){

	int n;
	cin>>n;

	int m;
	cin>>m;

	vector<pairs> list[n+1];

	for(int i=0;i<m;i++){

		int a,b,weight;
		cin>>a>>b>>weight;

		list[a].push_back({b,weight});

		list[b].push_back({a,weight});
	}

	int number_of_boose;

	cin>>number_of_boose;

	int dis[n+1]={};

	for(int i=0;i<n+1;i++)
		dis[i]=1000000;

	priority_queue<pairs,vector<pairs>,greater<pairs>> q; 

	for(int i=0;i<number_of_boose;i++){

		int boose_point;
		cin>>boose_point;

		q.push({0,boose_point});

		dis[boose_point]=0;
	}

	int vis[n+1]={};


	while(!q.empty()){


		pairs p = q.top();

		q.pop();

		if(vis[p.second])
			continue;

		vis[p.second]=1;

		// cout<<p.second<<" ";

		for(auto node:list[p.second]){

			if(dis[node.first]>dis[p.second]+node.second)
			{
				dis[node.first]=dis[p.second]+node.second;

				q.push({dis[node.first],node.first});
			}
		}




	}

	for(int i=1;i<n+1;i++){
		cout<<dis[i]<<" ";
	}









}