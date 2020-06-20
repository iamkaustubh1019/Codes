#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pairs;

int32_t main(){

	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){

		int n,m,queries;
		cin>>n>>m>>queries;

		// int (*mat)[1501] = new int[1501][1501];
		// int (*ans)[n+1] = new int[n+1][n+1];
		int mat[n+1][n+1];
		int ans[n+1][n+1];

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				mat[i][j] = INT_MAX;
				ans[i][j]=INT_MAX;
			}

		vector<pairs> list;

			for(int i=0;i<n;i++){

					mat[n][i]=0;
					list.push_back({n,i});
		}


		for(int i=0;i<m;i++){
			int a,b,weight;

			cin>>a>>b>>weight;
			list.push_back({a,b});
			mat[a][b]=weight;
		}

		int dis[n+1];
		for (int i = 0; i <= n; i++)
		{
			dis[i]=INT_MAX;
		}

		dis[n]=0;

		

		int count=n-1;

		while(count--){


			for(int i=0;i<m+n;i++)
			{

				int w = mat[list[i].first][list[i].second];
				int u = list[i].first;
				int v = list[i].second;

				if(mat[list[i].first][list[i].second]!=INT_MAX && dis[u]!=INT_MAX)
					{
			

						if(dis[v]>dis[u]+w)
							dis[v]=dis[u]+w;

					}


			}

		}


	

		for(int i=0;i<n;i++){

			for(int j=0;j<n;j++){

				if(mat[i][j]!=INT_MAX)


					mat[i][j] += dis[i]-dis[j]; 
				}
		}


		// for(int i=0;i<n;i++){

		// 	for(int j=0;j<n;j++){

		// 		cout<<mat[i][j]<<" ";

		// }
		// cout<<"\n";

	// }


	
		

		for(int k=0;k<n;k++){

			priority_queue<pairs,vector<pairs>,greater<pairs>> q;

			int distance[n]={};
			for (int i = 0; i < n; i++)
			{
				distance[i]=INT_MAX;
			}

			distance[k]=0;

			q.push({0,k});

			int vis[n]={};


			while(!q.empty()){

				pairs p = q.top();
				q.pop();

				int src = p.second;
				int cost = p.first;

				if(vis[src])
					continue;

				vis[src]=1;


				for(int i=0;i<n;i++){

					if(!vis[i] && mat[src][i]!=INT_MAX)
					{
						  distance[i] = min(distance[i],distance[src]+mat[src][i]);

       					  q.push({distance[i],i});
					}
				}


			}

			for(int i=0;i<n;i++)
				ans[k][i]=distance[i];

		}

		
		for(int i=0;i<queries;i++){
			int a,b; 
				cin>>a>>b;

		 	if(ans[a][b]==INT_MAX){
		 			cout<<"INF\n"; 
		 		} 

		  	else{

        		cout<<ans[a][b]-(dis[a]-dis[b])<<"\n"; 

        		} 

		        }








	}
}