#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

    int n;
    cin>>n;
    vector<int>mb(n);
    for(int i=0;i<n;i++)cin>>mb[i];

    int m;
    cin>>m;
    vector<int>pb(m);
    for(int i=0;i<m;i++)cin>>pb[i];

    int x=0;

    vector<int>a(m,0);

    for(int i=0;i<m;i++){
        for(int j=x;j<n;j++){
            if(pb[i]<=mb[j]){
                x=j+1;
                a[i]=j+1;
                break;
            }
        }
    }

    for(int i=0;i<m;i++){
        cout<<pb[i]<<" "<<a[i]<<endl;
    }

}