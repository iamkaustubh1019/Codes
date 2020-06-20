#include<bits/stdc++.h>
using namespace std;

struct Edge //edge object having two value
{
    int src;
    int dest;
};

class Graph
{
public:
     vector<vector<int>> adjList; //vector of vectors so as to have a list of edges corresponding to every node.

     Graph(vector<Edge> const &edges,int N)
     {
         adjList.resize(N);

         for (auto &edge: edges)
            {
            // insert at the end
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);//for bidirectional graphs
          }
     }


};

//function to check for edges
int check(Graph graph,int src,int dest)  {

    vector<vector<int>> adjList = graph.adjList;

    int length = adjList[src].size();

    for(int i=0;i<length;i++)
     {
         if(adjList[src][i] == dest)
         return 1;

     }
     return 0;
}



int main()
{
    int n,m;
    vector<Edge> edges;
    cin>>n;//number of nodes
    cin>>m;//number of edges

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a;
        cin>>b;
        Edge edg = {a,b};
        edges.push_back(edg);
    }

    Graph graph(edges,n);


    int q;
    cin>>q;

    for(int i=0;i<q;i++)
      {
          int a,b;
          cin>>a;
          cin>>b;
          if(check(graph,a,b))
          cout<<"YES\n";
          else
          cout<<"NO\n";

      }


      return 0;


}
