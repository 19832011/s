#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    int n;
    cin>>n;

    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b,i+1});
    }

    sort(v.begin(),v.end());

    vector<vector<int>>x;
    int k=0;
    for(int i=0;i<n;i++){
        if(v[i][0]>=k){
            int a;
            a=v[i][1]+v[i][0];
            x.push_back({a,v[i][2]});
        }else{
            int b;

            b=k+v[i][1];
            x.push_back({b,v[i][2]});
        }
        k=x[i][0];
    }
    cout<<"completion time  :: "<<endl;
    for(int i=0;i<n;i++){
        cout<<x[i][0]<<" "<<x[i][1]<<endl;
    }
    cout<<endl;
    vector<int>w(n,0);

    for(int i=0;i<n;i++){
        w[i]=x[i][0]-(v[i][0]+v[i][1]);
    }
    cout<<"waiting time :: "<<endl;
    for(int i=0;i<n;i++){
        cout<<w[i]<<" "<<x[i][1]<<endl;
    }
    // cout<<endl;
    cout<<endl;

    cout<<"trt  ::"<<endl;
    vector<int>t(n,0);
    for(int i=0;i<n;i++){
        t[i]=x[i][0]-v[i][0];
    }

    for(int i=0;i<n;i++){
        cout<<t[i]<<" "<<x[i][1]<<endl;
    }
    cout<<endl;

}