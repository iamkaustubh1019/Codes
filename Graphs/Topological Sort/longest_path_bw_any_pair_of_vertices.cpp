#include<bits/stdc++.h>
using namespace std;

//for directed graph


typedef pair<int,int> pairs;

int main(){
	int n;
	int m;
	cin>>n>>m;

	int ind[n+1]={};


	vector<pairs> list[n+1];

	for(int i=0;i<m;i++){
		int a,b,weight;

		cin>>a>>b>>weight;

		list[a].push_back({b,weight});

		ind[b]++;

	}
	int dist[n+1];
	queue<int> q;

	for(int i=0;i<n;i++){
		if(ind[i]==0){
	
			q.push(i);
		}
		dist[i]=0;
	}
	int mi=INT_MIN;


	while(!q.empty()){

		int curr_src=q.front();

		q.pop();
		

		for(auto node:list[curr_src]){

			if(dist[node.first]<dist[curr_src]+node.second)
				dist[node.first]=dist[curr_src]+node.second;

			mi = max(dist[node.first],mi);
			// cout<<"mi "<<mi<<"\n";

			if(--ind[node.first]==0){
				q.push(node.first);
			}
		}
	}

	for(int i=0;i<n;i++)
	cout<<"Distance of node"<<i<<" "<<dist[i]<<" \n";




	cout<<"ans "<<mi;

/* Output->>>>

6 6
0 1 1
1 2 2
2 3 3
3 4 4
4 5 5
2 5 100
Distance of node0 0 
Distance of node1 1 
Distance of node2 3 
Distance of node3 6 
Distance of node4 10 
Distance of node5 103 
ans 103


<<<-----------*/








}