
#include<bits/stdc++.h>

using namespace std;
//https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/to-buy-or-not-to-buy-6/


typedef pair<int,pair<int,int> >pairs;

int find(int var,int *parent){

	while(parent[var]>0){
		var = parent[var];
	}

	return var;
}
int gcd(int a,int b){
	if(b==0)
	return a;

	else return gcd(b,a%b);
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	int m;
	cin>>m;

    int (*mat)[1001]=new int[1001][1001];
    for(int i=1;i<1001;i++)
    for(int j=1;j<1001;j++)
    mat[i][j]=INT_MAX;
	vector<pairs> list;

	for(int i=0;i<m;i++){
		int a,b,weight;

		cin>>a>>b>>weight;

		list.push_back({weight,{a,b}});

	}

	sort(list.begin(),list.end());


	int parent[n+1]={};

	for(int i=1;i<=n;i++)
		parent[i]=-1;

		int weight=0;

	for(int i=0;i<m;i++){

		pairs p = list[i];

		int current_weight=p.first;
		int f=i;

		
		while(current_weight==list[++f].first){
			pairs p = list[f];
			int u = p.second.first;
			int v = p.second.second;
			

			int a = find(u,parent);
			int b = find(v,parent);
		
			if(a!=b){
				mat[u][v]=1;
				mat[v][u]=1;
			}
		}
	    p = list[i];


		int u = p.second.first;
		int v = p.second.second;
		

		int a = find(u,parent);
		int b = find(v,parent);
	
		if(a==b && a!=-1){
		
			continue;

		}

		weight=current_weight;


        mat[u][v]=1;
        mat[v][u]=1;


		if(parent[a]<=parent[b]){
			parent[a]+=parent[b];
			parent[b]=a;
		
		}

		else{
			parent[b]+=parent[a];
			parent[a]=b;

		}



	}
    int q;
    cin>>q;
    int count=0;


	for (int i = 1; i <=q; i++)
	{
		
        int a,b;
        cin>>a>>b;

        if(mat[a][b]==1)
        count++;
	}
	while(gcd(count,q)!=1){
     int k = gcd(count,q);
	 count/=k;
	 q/=k;
	}
	cout<<count<<"/"<<q<<"\n";



    }
	


}