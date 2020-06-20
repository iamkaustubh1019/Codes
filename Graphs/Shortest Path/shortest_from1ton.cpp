#include<bits/stdc++.h>
using namespace std;

#define Max 30000
int  main(){
    
    int a[Max]={};
    a[0]=0;
    a[1]=1;
    a[2]=1;
    a[3]=1;
    
    for(int i=4;i<Max;i++){
        if(i%3==0)
        
        a[i]=a[i/3]+1;
        
        else
        a[i]=a[i-1]+1;
        
        
    }
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<a[n]<<"\n";
    }
    
  
}