#include<bits/stdc++.h>
using namespace std;

// Graph is connected and undirected. that means atleast V-1 edges . 



int main(int argc, char const *argv[])
{
	int n;
	int m;

	vector<int> list[n+1];
	for (int i = 0; i < m; ++i)
	{
		int a,int b;

		cin>>a>>b;

		list[a].push_back(b);

		list[b].push_back(a);


	}




	return 0;
}