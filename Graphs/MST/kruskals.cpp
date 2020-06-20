#include<bits/stdc++.h>
 using namespace std;
 //greedy algorithm

 int find(int var,int *parent){

 	while(parent[var]>0)
 		var=parent[var];
 	return var;
 }

 int32_t main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


 	int n;
 	int m;
 	cin>>n>>m;

 	int parent[n+1];

 	fill(parent,parent+n+1,-1);

 	vector<pair<int,pair<int,int>> >list;

 	for(int i=0;i<m;i++){

 		int a,b,weight;

 		cin>>a>>b>>weight;

 		list.push_back({weight,{a,b}});
 	}


 	sort(list.begin(),list.end());
 	int cost=0;

 	for(int i=0;i<m;i++){


 		int u = list[i].second.first;
 		int v = list[i].second.second;

 		int a = find(u,parent);
 		int b = find(v,parent);

 		if(a==b)
 			continue;

 		if(parent[a]<=parent[b]){
 			parent[a]+=parent[b];
 			parent[b]=a;
 		}
 		else{
 			parent[b]+=parent[a];
 			parent[a]=b;
 		}
 		cost+=list[i].first;


 	}


 	cout<<cost<<"\n";
 }