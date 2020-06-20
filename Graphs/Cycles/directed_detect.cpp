#include<bits/stdc++.h>
using namespace std;
bool detect_cycle(vector<int> list[],int *vis,int src,int *completely_visited){

	vis[src]=1;

	for(auto node:list[src]){

		if(completely_visited[node])
			continue;
		
		if(vis[node]){
			
				return true;
				}
			if(detect_cycle(list,vis,node,completely_visited))
				return true;
		
	}

	completely_visited[src]=1;

	return false;


}
int main(){

	int t;
	cin>>t;
	while(t--){
	
		int n;
		int m;
	
		cin>>n;
		cin>>m;
	
		vector<int> list[n];
	
		for(int i=0;i<m;i++){
	
			int a,b;
	
			cin>>a>>b;
	
			list[a].push_back(b);
		}
	
	
		int vis[n]={};
		int flag=0;
		int completely_visited[n]={};

		for(int i=0;i<n;i++){
		if(!vis[i])
		if(detect_cycle(list,vis,i,completely_visited)){
			cout<<i<<"\n";

			cout<<"Has a Cycle\n";
			flag=1;
		}
		}
		if(!flag){
			cout<<"No Cycle\n";
		}
		
	}
}

/* Output

3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2

Has a Cycle

No Cycle

Has a Cycle


1
61 34
45 16 54 29 12 41 36 13 9 31 49 52 46 53 22 4 8 11 35 19 11 54 22 47 30 37 42 53 44 47 54 28 4 47 59 19 29 35 32 39 5 23 32 51 17 55 57 25 7 31 46 18 26 8 6 57 45 50 51 30 37 47 60 43 35 59 1 4
No Cycle


1
29 4
6 21 17 12 2 11 9 11
No Cycle


*/