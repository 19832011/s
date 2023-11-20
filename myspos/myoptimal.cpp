#include<bits/stdc++.h>
using namespace std;
// #define int long long

int main(){
    int n,f;
    cin>>n>>f;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<int>x;
    int a =0;
    for(int i=0;i<n;i++){
        if(x.size()<f){
            if(find(x.begin(),x.end(),v[i])==x.end()){
                x.push_back(v[i]);
                a++;
            }
        }else{
            if(find(x.begin(),x.end(),v[i])==x.end()){
                vector<vector<int>>k;
                for(int l=0;l<x.size();l++){
                    int r=n;
                    for(int j=i+1;j<n;j++){
                        if(x[l]==v[j]){
                            r=j;
                            break;
                        }
                    }
                    k.push_back({r,l});
                }
                sort(k.begin(),k.end());
                reverse(k.begin(),k.end());
                int s=k[0][1];
                x[s]=v[i];
                a++;
            }
        }
        for(int p=0;p<x.size();p++){
            cout<<x[p]<<" ";
        }
        cout<<endl;

    }
    cout<<a<<endl;

}