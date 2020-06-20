#include<bits/stdc++.h>
 using namespace std;
 //greedy algorithm https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/rebuild/

 int find(int var,int *parent){

 	while(parent[var]>0)
 		var=parent[var];
 	return var;
 }

 typedef pair<long long int ,pair<int,int>> pairs;

 bool compare(pairs p1,pairs p2){
 	if(p1.first==p2.first){

 		if (p1.second.first==p2.second.first)
 			return p1.second.second>p2.second.second;
 		else return p1.second.first>p2.second.first;
 	}
 	return p1.first<p2.first;
 }

 int32_t main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin>>t;

    while(t--){


 	int n;
 	int m;
 	cin>>n>>m;

 	int parent[n+1];

 	fill(parent,parent+n+1,-1);

 	vector<pair<long long int ,pair<int,int>> >list;

 	for(int i=0;i<m;i++){

 		int a,b;
 		long long int weight;

 		cin>>a>>b>>weight;

 		list.push_back({weight,{min(a,b),max(a,b)}});
 	}

 	int deg[n+1]={};


 	sort(list.begin(),list.end(),compare);
 	long long int cost=0;

 	for(int i=0;i<m;i++){


 		int u = list[i].second.first;
 		int v = list[i].second.second;

 		int a = find(u,parent);
 		int b = find(v,parent);

 		if(a==b)
 			continue;

 		deg[u]++;
 		deg[v]++;

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

 	for(int i=1;i<=n;i++)
 		cout<<deg[i]<<" ";
 	cout<<"\n";
}

}