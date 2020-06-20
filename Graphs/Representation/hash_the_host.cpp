#include<bits/stdc++.h>
using namespace std;


int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin>>n;

    // int a[n+1]={0};
    vector<pair<int,int>> vp;
    for(int i=1;i<=n;i++)
    vp.push_back({0,i});
    vector<vector<int>> v;
    v.resize(n+1);

    for(int i=0;i<n;i++){
        int num;
        cin>>num;

        for(int j=0;j<num;j++){
            int ind;
            cin>>ind;
            v[i+1].push_back(ind);
            // a[ind]++;

            vp[i].first++;
        }
    }

    sort(vp.begin(),vp.end());
    unordered_set<int> uset;

    for(int i=1;i<n+1;i++){

        int size = v[vp[i].second].size();

        bool flag=false;

        for(int j=0;j<size;j++)
        {
            if (uset.find(v[vp[i].second][j])!=uset.end()){
                flag=true;
                break;
            }
        }
        if (!flag){
            cout<<i<<" ";
            uset.insert(i);
        }
    }




    cout<<uset.size();






}
