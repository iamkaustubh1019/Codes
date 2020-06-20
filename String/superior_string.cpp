#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int m=INT_MIN;
		for(int i=0;i<n;i++){
			int a[26]={};
			for(int j=i;j<n;j++){

				a[s[j]-'a']++;
				for(int k=0;k<26;k++)
				if((j-i+1)/2==a[k]){

					m = max(j-i+1,m);

				}

			}
		}

		cout<<m;
	}
}