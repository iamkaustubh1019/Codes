#include<bits/stdc++.h>
using namespace std;

// A directed acyclic graph has at least one vertex which has zero indegree  
//and zero outdegree else the graph would be cyclic.


int main(){
	int n;
	cin>>n;

	int m;

	cin>>m;

	vector<int> list[n+1];

	int ind[n+1]={};
	int out[n+1]={};

	for(int i=0;i<m;i++){

		int a;
		int b;
		cin>>a>>b;
		ind[b]++;
		out[a]++;
		list[a].push_back(b);
	}

	queue<int> q;
	queue<int> ans;

	for(int i=1;i<=n;i++){
		if(!ind[i]){

			q.push(i);
		
		}
	}

	// int arr[n+1];



	while(!q.empty()){

		int curr_node=q.front();

		ans.push(curr_node);

		q.pop();

		if(!out[curr_node])
			continue;
	

		for(auto node:list[curr_node]){
			ind[node]--;
			if(ind[node]==0)
				q.push(node);


		}




	}


	while(!ans.empty()){
		cout<<ans.front()<<" ";
		ans.pop();

	}










}