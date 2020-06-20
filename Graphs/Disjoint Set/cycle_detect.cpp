#include<bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int> >pairs;

int find(int var,int *parent){

	while(parent[var]>0){
		var = parent[var];
	}

	return var;
}


int32_t main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int m;
	cin>>m;

	vector<pairs> list;

	for(int i=0;i<m;i++){
		int a,b,weight;

		cin>>a>>b>>weight;

		list.push_back({weight,{a,b}});

	}

	sort(list.begin(),list.end());


	int parent[n+1]={};

	for(int i=1;i<=n;i++)
		parent[i]=-1;

	for(int i=0;i<m;i++){

		pairs p = list[i];

		int u = p.second.first;
		int v = p.second.second;
		

		int a = find(u,parent);
		int b = find(v,parent);
	
		if(a==b && a!=-1){
			cout<<"Cycle Detected in edges "<<u<<" and "<<v<<" .\n";
			continue;
		}


		cout<<u<<" "<<v<<"\n";


		if(parent[a]<=parent[b]){
			parent[a]+=parent[b];
			parent[b]=a;
		
		}

		else{
			parent[b]+=parent[a];
			parent[a]=b;

		}



	}

	for (int i = 1; i <=n; ++i)
	{
		cout<<parent[i]<<" ";
	}



	return 0;
}