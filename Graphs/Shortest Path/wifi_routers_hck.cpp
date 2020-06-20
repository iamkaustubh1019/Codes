#include<bits/stdc++.h>
using namespace std;
#define Max 101

typedef pair<int,pair<int,int>> pairs; 

typedef pair<int,int> pair_;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 


bool if_possible(int i,int j){

	if(i>=0 && i<=100 && j>=0 && j<=100)
		return true;
	return false;
}


int main(){

	int mat[Max][Max][Max];



	int test_cases;
	cin>>test_cases;

	while(test_cases--){

		int mat[Max][Max];
		for(int i=0;i<Max;i++){
			for(int j=0;j<Max;j++){
				mat[i][j]=1000000;
			}
		}



		int number_of_routers;
		cin>>number_of_routers;

		int number_of_users;
		cin>>number_of_users;


		// vector<pair<int,int>> vpr;

		vector<pair<int,int>> vpu;

		unordered_map<pair_,pair_,hash_pair> umap;



		priority_queue<pairs,vector<pairs>,greater<pairs>> q;

		for(int i=0;i<number_of_routers;i++)
		{
			int a,b;
			cin>>a>>b;
			q.push({0,{a,b}});
			

		} 

		for(int j=0;j<number_of_users;j++){
			int a,b;
			cin>>a>>b;

			umap[{a,b}]={a,b};
			mat[a][b] = 0;

			
			// umap[{a,b}]={-1,-1};
		}



		while(!q.empty()){

			pairs p = q.top();

			q.pop();

			int dis = p.first;

			int i = p.second.first;

			int j = p.second.second;

			if(dis>mat[i][j])
				continue;


			if(if_possible(i+1,j)){
				if(mat[i+1][j]>dis+1)
					{
						mat[i+1][j]=dis+1;

						q.push({dis+1,{i+1,j}});

						umap[{i+1,j}]=umap[{i,j}];


					}
			}

			if(if_possible(i,j+1)){
				if(mat[i][j+1]>dis+1)
					{
						mat[i][j+1]=dis+1;

						q.push({dis+1,{i,j+1}});

						umap[{i,j+1}]=umap[{i,j}];

					}
			}

			if(if_possible(i,j-1)){
				if(mat[i][j-1]>dis+1)
					{
						mat[i][j-1]=dis+1;

						q.push({dis+1,{i,j-1}});

						umap[{i,j-1}]=umap[{i,j}];

					}
			}
			if(if_possible(i-1,j)){
				if(mat[i-1][j]>dis+1)
					{
						mat[i-1][j]=dis+1;

						q.push({dis+1,{i-1,j}});

						umap[{i-1,j}]=umap[{i,j}];

					}
			}

		}

		double m=-1;

		for(int i=0;i<number_of_users;i++){
			// m=max(m,mat[vpu[i].first][vpu[i].first]);
			pair_ p = vpu[i];
			pair_ mapped = umap[p];

			int first = abs(p.first-mapped.first);
			int second = abs(p.second-mapped.second);


			m = max(m,(double)(first*first+second*second));
			cout<<m<<" "<<p.first<<" "<<p.second<<" "<<mapped.first<<" "<<mapped.second<<"\n";

		}

		std::cout << std::setprecision(6) << std::fixed;

		cout<<sqrt(m)<<"\n";



	}


	return 0;

}