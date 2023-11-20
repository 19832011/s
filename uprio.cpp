#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"enter the no. of process";
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(7));
    cout<<"enter arr_T   bust_T  PRIORITY \n";
    for(int i=0;i<n;i++){
        cin>>v[i][1]>>v[i][2]>>v[i][0];
        v[i][0]=-v[i][0];
        v[i][3]=i+1;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<"arr"<<v[i][1]<<" b"<<v[i][2]<<" p"<<v[i][0];
    }
    cout<<" \n grant chart \n";
    int x;
    for(int i=0;i<n;i++){
        if(v[i][1]==0){
            cout<<v[i][3];
             v[i][4]=v[i][1]+v[i][2];
             x=v[i][4];

        }
    }
    v[0][4]=v[0][2]+x;
    for(int i=1;i<n;i++){
       
       if(v[i][1]!=0){
            v[i][4]=v[i-1][4]+v[i][2];
             cout<<v[i][3]<<" ";
        }
        v[i][5]=v[i][4]-v[i][1];
        v[i][6]=v[i][5]-v[i][2];
    }
    cout<<endl;
    cout<<"pid \t A T \t B T\t pri \t complt T  \t tot \t wait T \n";
    for(int i=0;i<n;i++){
        v[i][0]=-v[i][0];
        cout<<v[i][3]<<"\t"<<v[i][1]<<"\t"<<v[i][2]<<"\t"<<v[i][0]<<"\t"<<v[i][4]<<"\t"<<v[i][5]<<"\t"<<v[i][6]<<endl;
    }
    return 0;
}