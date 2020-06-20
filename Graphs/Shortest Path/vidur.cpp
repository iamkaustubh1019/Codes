#include<bits/stdc++.h>
using namespace std;
#define max 10000000000000000
void dijkistra(vector<pair<long long, int>> v[], long long dis[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, 1});
    dis[1] = 0;
    while(!p.empty()){
        pair<long long, int> u = p.top();
        p.pop();
        int m = u.second;
        for(int i=0; i<v[m].size(); i++){
            int e = v[m][i].second;
            long long w = v[m][i].first;
            if(dis[m]+w<dis[e]){
                dis[e] = dis[m]+w;
                p.push({dis[e], e});
            }
        }
    }
}
int main(){
    int n, m, f;
    cin>>n>>m>>f;
    int a[n+1];
    for(int i=1; i<=n; i++)
    cin>>a[i];
    vector<pair<long long, int>> v[n+1];
    long long dis[n+1];
    for(int i=1; i<=n; i++)
    dis[i] = max;
    for(int i=0; i<m; i++){
        int b, c;
        long long w;
        cin>>b>>c>>w;
        v[b].push_back(make_pair(w, c));
        v[c].push_back(make_pair(w, b));
    }
    int k;
    cin>>k;
    long long ans[100000];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> d;
    dijkistra(v, dis);
    for(int i=1; i<=n; i++){
        if(dis[i]!=max)
        d.push({dis[i], i});
    }
    int r=0;
    while(!d.empty()){
        pair<long long, int> u = d.top();
        d.pop();
        int e = u.second, w = u.first;
        for(int i=0; i<a[e]; i++){
            ans[r] = w+f;
            r++;
            if(r==k)
            break;
        }
        if(r==k)
        break;
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<a[i]; j++){
    //         ans[r] = dis[i]+f;
    //         r++;
    //     }
    // }
    // sort(ans, ans+r);
    if(r<k){
        for(int i=r; i<k; i++)
        ans[i] = -1;
    }
    for(int i=0; i<k; i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}