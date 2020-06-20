#include<bits/stdc++.h>
 using namespace std;
 //greedy algorithm
#define MAX 10000000
 int find(int var,int *parent){

 	while(parent[var]>0)
 		var=parent[var];
 	return var;
 }
typedef pair<int,int> pairs;
 int32_t main(){
 	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    // cin>>t;
    scanf("%d",&t);

    for(int l=0;l<t;l++){



    cout<<"Case: "<<l+1<<"\n";
    


 	int n;
 	int m;
    int queries;
 	// cin>>n>>m>>q;
     scanf("%d %d %d",&n,&m,&queries);

 	int parent[n+1];

 	fill(parent,parent+n+1,-1);
    int mat[1001][1001]={};
	int ans[1001][1001]={};
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            mat[i][j]=MAX;
			ans[i][j]=MAX;

        }
    }

 	vector<pair<int,pair<int,int>> >list;

 	for(int i=0;i<m;i++){

 		int a,b,weight;

 		scanf("%d %d %d",&a,&b,&weight);

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

         mat[u][v]=list[i].first;
         mat[v][u]=list[i].first;


 	}

    //  for (int k=1;k<=n;k++){
    //      for(int i=1;i<=n;i++){
    //          for(int j=1;j<=n;j++){
    //              mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
    //          }
    //      }
    //  }
	for(int k=1;k<=n;k++){
		priority_queue<pairs> q;
		q.push({0,k});
		int dist[n+1]={};
		for(int i=0;i<n+1;i++){
			dist[i]=100000000;
		}

		dist[k]=0;
		int vis[n+1]={};
	
		while(!q.empty()){
			pairs p = q.top();
			q.pop();

			int cost = p.first;
			int src=p.second;

			if(vis[src])
			continue;
			vis[src]=1;

			for(int i=1;i<=n;i++){
				if(!vis[i] && mat[src][i]!=MAX)
				if(dist[i]>dist[src]+mat[src][i]){
					dist[i]=dist[src]+mat[src][i];
					q.push({dist[i],i});
				}
			}


		}

		for(int i=1;i<=n;i++){
			ans[k][i]=dist[i];
		}


	}
    
     for(int i=0;i<queries;i++){
         int a,b;
         cin>>a>>b;
        //  cout<<mat[a][b]<<"\n";
        printf("%d\n",ans[a][b]);

     }




    }
 }