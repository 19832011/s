#include<bits/stdc++.h>
using namespace std;
// #define int long long
int main(){

    int n;
    cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int a,b,c;
        
        cin>>a>>b>>c;
        v.push_back({a,b,c,i+1});
    }
    sort(v.begin(),v.end());

    vector<vector<int>>x;
    int z=v[0][0];
    int r=0;
    vector<int>vis(n+1,0);
    while(true)
    {
        // cout<<"w"<<endl;
        bool flag = true;
        for(int i=0; i<n; i++)
        {
            if(vis[v[i][3]] == 0) flag = false;
        }
        if(flag) break;
        vector<vector<int>>k;
        for(int i=0;i<n;i++)
        {
            if(v[i][0]<=z and vis[v[i][3]] == 0)
            {
                // cout<<"l"<<endl;
                k.push_back({v[i][1],v[i][0],v[i][2],v[i][3]});
                
            }
        }
        sort(k.begin(),k.end());
        
        vis[k[0][3]] = 1;

        z = max(z, k[0][1]) + k[0][2];

        x.push_back({z, k[0][3]});

    }

    cout<<"completion time  :: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<x[i][0]<<" "<<x[i][1]<<endl;
    }
    cout<<endl;
} 