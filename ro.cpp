#include<bits/stdc++.h>
using namespace std;
int main(){
cout<<"enter the no of process \n";
int n;
cin>>n;
cout<<"enter time quanta \n";
int qt;
cin>>qt;
vector<vector<int>>v(n,vector<int>(7));

cout<<"enter arri and burst\n";
for(int i=0;i<n;i++){
    cin>>v[i][0]>>v[i][1];
    v[i][2]=i;
    v[i][6]=v[i][1];

}
queue<vector<int>>q;
int time(0);
int cnt(0);
vector<int>vis(n,0);
while(true){
if(q.empty() and cnt>=n)break;

for(int i=0;i<n;i++){
    if(vis[i]==0){
        if(v[i][0]<=time){
            q.push(v[i]);
            vis[i]=1;
            cnt++;
        }
    }
}
if(q.empty())time++;
vector<int>temp =q.front();
q.pop();
if(temp[1]>qt){
   temp[1]-=qt;
   time+=qt;
   for(int i=0;i<n;i++){
    if(vis[i]==0){
        if(v[i][0]<=time){
            q.push(v[i]);
            vis[i]=1;
            cnt++;
        }
    }
   }
   q.push(temp);
   }else{
    time+=temp[1];
    
    
    v[temp[2]][3]=time;
    v[temp[2]][4]=v[temp[2]][3]-v[temp[2]][0];
    v[temp[2]][5]=v[temp[2]][4]-v[temp[2]][6];
   

}

}
for(int temp=0;temp<n;temp++){
cout<<v[temp][0]<<" "<<v[temp][6]<<" "<<v[temp][3]<<" "<<v[temp][4]<<" "<<v[temp][5]<<endl;
}









    return 0;
}