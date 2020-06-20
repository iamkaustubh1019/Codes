#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pairs;
typedef pair<int,pair<int,string>> pair_path;



int32_t main(){


  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int m;

  cin>>n>>m;
  vector<pairs> list[n+1];

  for(int i=0;i<m;i++){
  	int a,b,weight;
  	cin>>a>>b>>weight;

  	if(a==b)
  		continue;
  	else{
  		list[a].push_back({b,weight});
  		list[b].push_back({a,weight});
  	}

  }

  priority_queue< pairs,vector<pairs>,greater<pairs>> q;

  q.push({0,1});

  int vis[n+1]={};

  int dis[n+1]={};
  int parent[n+1]={};

  for(int i=1;i<n+1;i++){
  	dis[i]=INT_MAX;
  	parent[i]=-1;
  }



  bool flag=false;
  stack<int> s;

  while(!q.empty()){

  	pairs p = q.top();
  	int curr_node = p.second;
  	int dist = p.first;
  	

  	if(curr_node==n){
  		// cout<<path<<curr_node;
  		while(n!=1){
  			s.push(n);
        // cout<<n<<" ";
        n=parent[n];
   		 }
    	// cout<<1;
   		 s.push(1);

  		flag=true;
  		break;
  	}
  
  	q.pop();
  	if(vis[curr_node])
  		continue;
  	vis[curr_node]=1;

  	for(auto node:list[curr_node]){

  		if(dist+node.second<dis[node.first] && !vis[node.first])
  		{
  			dis[node.first]=dist+node.second;
  			q.push({dis[node.first],node.first});
  			parent[node.first]=curr_node;
  		}

  	}
  }
  while(!s.empty()){
  	cout<<s.top()<<" ";
  	s.pop();
  }
  if(!flag)
  	cout<<"-1";





}