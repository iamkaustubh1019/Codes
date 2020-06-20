#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	int m;
	cin>>n;
	cin>>m;

	vector<int> list [n+1];
	int ind[n+1]={};
	int out[n+1]={};

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;

		ind[b]++;
		out[a]++;
		list[a].push_back(b);

	}


	int q[n];

	int front=0,count=0;

	int parent[n+1]={};

	for(int i=1;i<n+1;i++){
		if(ind[i]==0)
		{
			q[count]=i;
			count++;
			// parent[i]=-1;
		}
	}



	while(front!=n-1){

		int curr_src=q[front];
		front++;

		if(!out[curr_src])
			continue;
		for(auto node:list[curr_src]){

			ind[node]--;
			if(!ind[node]){
				q[count]=node;
				count++;
			
			}


		}


	}




	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			//prints all the edges including given edges and possible edges
			cout<<q[i]-1<<"-->"<<q[j]-1<<"\n";
			
			
		}
	}



}