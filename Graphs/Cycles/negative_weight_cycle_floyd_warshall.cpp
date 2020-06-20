#include<bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){

		int n;
		int m;

		cin>>n;
		cin>>m;

		int mat[100][100];
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j< n; j++)
			{
				mat[i][j]=INT_MAX;
			}
		
		}


		for(int i=0;i<m;i++){
			int a,b,weight;
			cin>>a>>b>>weight;

			mat[a][b]=weight;
			mat[b][a]=weight;

		}


		for(int k=0;k<n;k++){
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
				}
				 // code 
			}
		}

		int ma = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			ma = min(ma,mat[i][i]);
			/* code */
		}

		if(ma<0)
			cout<<ma<<" 1\n";

		else{
			cout<<"0\n";
		}
	}


}