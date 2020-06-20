#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,string> pairs;
void dfs(){

}

int main()
{
	//code
	int t;
	cin>>t;
	while(t--){

      int n;
      int m;
      cin>>n>>m;
      vector<vector<int>> list;
      string str;
      str.resize(n);
      fill(str.begin(),str.end(),'0');

      list.resize(n+1);

      for (int i=0;i<m;i++)
         {
           int a,b;
           cin>>a>>b;
           list[a].pb(b);

         }


    	int src,dest;
    	cin>>src>>dest;
    	int count =0;

    	stack<pairs> s;
    	str[src] = '1';
    	s.push(make_pair(src,str));

    	while(!s.empty()){
    	    pairs ps;
          ps = s.top();
          // s.pop();
          // cout<<"here "<<ps.first<<" size "<<s.size()<<"\n";

    	    for(auto &node:list[ps.first]){

    	        if(ps.second[node]=='0'){
                 // cout<<" "<<node<<" "<<ps.first<<" "<<ps.second<<" ";
    	            if (node==dest)
    	            {count++;}
    	            string st = ps.second;
                  ps.second[node] = '1';
                  // cout<<ps.second<<"\n";
    	            st[node]='1';
                  s.pop();
                  s.push(ps);
    	            s.push(make_pair(node,st));
                  // cout<<s.top().first<<"\n";
    	            break;
    	        }
    	    }

          if(s.top()==ps)
    	    {
            // cout<<"popped->"<<s.top().first<<"\n";
            s.pop();

          }

    	}


      std::cout << count << '\n';
}


    	return 0;
}
