#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int test_cases;
	cin>>test_cases;
	while(test_cases--){
		int number_of_edges;
		cin>>number_of_edges;

		int m[31]={};

		for(int i=0;i<number_of_edges;i++){
			int a,b;
			cin>>a>>b;
			if(a<b)
				m[a]=b;
			else
				m[a]=-1;
		}

		queue<int> q;
		int vis[31]={};
		vis[1]=0;
		q.push(1);
		queue<int>  q2;


		while(!q.empty()){


			int src=q.front();

			// cout<<src<<" ";


			q.pop();
			// cout<<"here\n";

			

			for(int i=1;i<=6;i++){

				if(src+i==30){
				cout<<vis[src]+1<<'\n';
				q2.swap(q);

				break;
				}

				if(m[src+i]==30){
				cout<<vis[src]+1<<'\n';
				q2.swap(q);

				break;

				}

				if(m[src+i]!=-1 ){
					// cout<<i<<" \n";
					if(m[src+i]==0 && vis[src+i]==0){
						// cout<<i<<" \n";

						q.push(src+i);
						vis[src+i]=vis[src]+1;
					}
					else if(vis[m[src+i]]==0)
						{
							q.push(m[src+i]);
							vis[m[src+i]]=vis[src]+1;
						}
				}
			}
		}


	}

}