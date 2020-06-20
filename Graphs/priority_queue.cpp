#include<bits/stdc++.h>
using namespace std;



class Val{
  public:

        int a;
        string s;

        Val(int a,string s):a(a),s(s){
        }

};
//ye important hai yahan hum operator overloading  kar re basically jab priority queue me element dalenge to vo < operator se compare lagaega
// ie v1 < v2
// tabhi < is walle se use hoga

bool operator<(const Val& v1,const Val& v2){
    if (v1.a<v2.a){
      return true;
    }

    if (v1.a==v2.a)
    return v1.s<v2.s;

    else return false;
}

int main(){
  priority_queue<Val> pq;
  Val v(1,"hi");
  Val v1(2,"hehehe");
  Val v2(3,"hahah");
  Val v3(3,"hhaaa");
  pq.push(v);
  pq.push(v1);
  pq.push(v2);
  pq.push(v3);
  if (2<3)
  cout<<"YES";

 while(!pq.empty()){
   Val node = pq.top();
    cout<<node.a<<" "<<node.s<<"\n";
    pq.pop();

 }
}
