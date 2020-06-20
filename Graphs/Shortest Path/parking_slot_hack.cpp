#include<bits/stdc++.h>

using namespace std;

typedef pair<long long int,long long int> pairs;

int main(){


    int n,m,f;

    cin>>n;
    cin>>m;
    cin>>f;

    vector<pairs> list[n+1];


    int val[100001];

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        // cout<<i<<" ";
        val[i+1]=a;
    }


    for(int i=0;i<m;i++){
        // cout<<i<<m<<" ";
        long long int  a,b,weight;
        cin>>a>>b>>weight;

        list[a].push_back({b,weight});
        list[b].push_back({a,weight});
    }

    int k;
    cin>>k;

    int vis[n+1]={};

    long long int  dis[n+1]={};

    for(int i=0;i<n+1;i++){
        vis[i]=0;
        dis[i]=1000000000000;
    }

    priority_queue<pairs,vector<pairs>,greater<pairs>> q;

    q.push({0,1});
    dis[1]=0;

    queue<int> ans;
    int count=0;

    while(!q.empty()){

        pairs p = q.top();
        q.pop();

        // cout<<p.second<<" ";

        if(vis[p.second]==1)
            continue;

        

        vis[p.second]=1;
        ans.push(p.second);
        count++;

        if(count==k)
            break;

       

        for(auto node:list[p.second]){

            if(vis[node.first]==0){

               dis[node.first] = min(dis[node.first],dis[p.second]+node.second);
               q.push({dis[node.first],node.first});
            }
        }
    }
    count = k;
    // cout<<ans.front()<<" ";

    while(!ans.empty()){

        int a = ans.front();
        ans.pop();
        // cout<<a;

        while(val[a]--){

            if(count>0){
                count--;
                cout<<dis[a]+f<<" ";
            }

        }

    }

    while(count>0){
        cout<<"-1 ";
        count--;
    }




}