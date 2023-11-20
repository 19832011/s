#include<bits/stdc++.h>
using namespace std;
// #define int long long

int main(){
    int n,f;
    cin>>n>>f;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<int>x;
    map<int,int>m;
    int a=0;
    for(int i=0;i<n;i++){
        if(x.size()<f){
            if(find(x.begin(),x.end(),v[i])==x.end()){
                x.push_back(v[i]);
                a++;
            }
        }else{
            if(find(x.begin(),x.end(),v[i])==x.end()){
                int y=INT_MAX;
                int u;
                for(int h=0;h<x.size();h++){
                    if(y>m[x[h]]){
                        y=m[x[h]];
                        u=x[h];
                    }
                }
                for(int j=0;j<x.size();j++){
                    if(x[j]==u){
                        x[j]=v[i];
                    }
                } 
                a++;
            }
        }
        m[v[i]]=i;
        for(int k=0;k<x.size();k++){
            cout<<x[k]<<" ";
        }
        cout<<endl;
    }
    cout<<a<<endl;

}