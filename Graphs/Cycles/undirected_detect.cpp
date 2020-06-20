#include<bits/stdc++.h>
using namespace std;

bool detect_cycle(int *vis,vector<int> list[],int src,int *parent ){
    vis[src]=1;
    
    for(auto node:list[src]){
        
        if(vis[node] && node!=parent[src] )
        return true;
        
        else if(!vis[node] ){
            parent[node]=src;
        if(detect_cycle(vis,list,node,parent))
        return true;
        }
    }
    
    return false;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		int m;
		cin>>n>>m;

		vector<int> list[n+1];

		for(int i=0;i<m;i++){
			int a, b;
			cin>>a>>b;

			list[a].push_back(b);
			list[b].push_back(a);

		}


		int vis[n]={};

		bool flag=false;
		int parent[n+1];
		fill(parent,parent+n,-1);

		for(int i=0;i<n;i++){
			if(!vis[i]){
				if(detect_cycle(vis,list,i,parent)){
					// cout<<i<<" \n";
					flag=true;
					break;
				}
			}
		}

		if(flag)
			cout<<"Has a cycle\n";
		else
			cout<<"No cycle\n";
	}
	return 0;
}


/* Output


3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2

Has a cycle

No cycle

Has a cycle



*/