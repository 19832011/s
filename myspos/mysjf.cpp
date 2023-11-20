#include<bits/stdc++.h>
using namespace std;
// #define int long long
int main(){

    int n;
    cin>>n;
    int mi=INT_MAX;
    int ma=INT_MIN;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b,i+1});
        mi=min(a,mi);
        ma=max(ma,a);
    }

    sort(v.begin(),v.end());

    vector<vector<int>>x;
    vector<int>vis(n+1,0);

    for(int i=0;i<n;i++){
        if(v[i][0]==mi){
            x.push_back({v[i][1],v[i][0],v[i][2]});
            vis[v[i][2]]=1;
        }
        
    }
    int a=mi;
    vector<int>ans(n+1,0);
    
    while(true){
        
        if(x.size()==0 && a>ma){
            break;
        }else if(x.size()!=0){
            sort(x.begin(),x.end());
            // cout<<x[0][2]<<"-";
            x[0][0]--;
            if(x[0][0]==0){
                ans[x[0][2]]=a+1;
                x.erase(x.begin());
            }
        }
        a++;
        // cout<<a<<" "<<x.size()<<endl;
        for(int i=0;i<n;i++){
            if(v[i][0]==a && vis[v[i][2]]==0){
                x.push_back({v[i][1],v[i][0],v[i][2]});
                vis[v[i][2]]=1;
            }
        }
    }

    for(int i=0;i<n+1;i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;


}