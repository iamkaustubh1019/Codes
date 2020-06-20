#include<bits/stdc++.h>
using namespace std;


typedef pair<long long int,long long int> pairs;
int main(){

	int n;
	int m;

	cin>>n;
	cin>>m;

	vector<pairs> list ;


	priority_queue<pairs,vector<pairs>,greater<pairs>> q;

	long long int ans=pow(2,n)-1;

	for(int i=0;i<m;i++){

		list.push_back({0,0});

		for(int j=0;j<n+1;j++){



			if(j==n)
			{
				long long int a;
				cin>>a;
				list[i].first=a;
			}

			else{
				int a;
				cin>>a;

				if(a==1)
					list[i].second+=pow(2,j);

			}

		}

		q.push({list[i].first,list[i].second});


	}



	unordered_map<long long int,long long int> umap;

	while(!q.empty()){

		pairs p = q.top();

		q.pop();


		if(p.second==ans){
			cout<<p.first<<"\n";
			break;
		}

		umap[p.second]=p.first;

		for(int i=0;i<m;i++){

			long long int s = p.second|list[i].second;

			if(umap.find(s)!=umap.end()){

				if(umap[s]>p.first+list[i].first)
				   {
				   	umap[s]=p.first+list[i].first;
				   	q.push({umap[s],s});
				   }

			}
			else
			{
				 	umap[s]=p.first+list[i].first;

				   	q.push({umap[s],s});

			}

		}

	}







}
