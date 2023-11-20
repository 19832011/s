#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int>mb(n);
    for(int i=0;i<n;i++){
        cin>>mb[i];
    }
    int m;
    cin>>m;
    vector<int>pb(m);
    for(int i=0;i<m;i++){
        cin>>pb[i];
    }
    vector<int>v(m,0);
    for(int i=0;i<m;i++){
        int y=-1;
        int p=INT_MAX;
        for(int j=0;j<n;j++){
            if(mb[j]-pb[i]<p && mb[j]-pb[i]>=0){
                y=j;
                p=mb[j]-pb[i];
            }
        }
        if(y!=-1){
            v[i]=y+1;
            mb[y]=mb[y]-pb[i];
        }
    }

    for(int i=0;i<m;i++){
        cout<<i<<" "<<pb[i]<<" "<<v[i]<<endl;
    }

}