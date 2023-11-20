#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"enter the no. of processes \n";
    int n;
    cin>>n;
    int choice;
    cout<<"enter 3 for roundrobin \n enter 4 for sjf \n";
    cin>>choice;
    if(choice==3){
        int t;
        cout<<"enter time quanta \n";
        cin>>t;
        vector<vector<int>>v(n,vector<int>(7));
        cout<<"enter arrival_time  burst_time \n";
        for(int i=0;i<n;i++){
            cin>>v[i][0]>>v[i][1];
            v[i][2]=i;
            v[i][6]=v[i][1];
        }
        queue<vector<int>>q;
        int time=0,count=0;
        vector<int>vis(n,0);
        //cout<<"pr_id\t arr\t bust\t cmplt\t tot\t wt\n";
        // while(true){
        //     if(q.empty() && count>=n)break;
        //     //cout<<10000<<endl;
        //     if(q.empty())time++;
        //     for(int i=0;i<n;i++){
        //         if(v[i][0]<=time and vis[i]==0){
        //             q.push(v[i]);
        //             vis[i]=1;
        //             count++;
        //         }
        //     }
        //     vector<int>temp=q.front();
        //     q.pop();
        //     if(temp[6]>t){
        //         temp[6]-=t;
        //         time+=t;
        //         //cout<<temp[2]<<"\t"<<temp[0]<<"\t"<<temp[1]<<"\t"<<temp[3]<<"\t"<<temp[4]<<"\t"<<temp[5]<<endl;
        //         for(int i=0;i<n;i++){
        //             if(v[i][0]<=time and vis[i]==0){
        //                 q.push(v[i]);
        //                 vis[i]=1;
        //                 count++;
        //             }
        //         }
        //         q.push(temp);
        //     }
        //     else{
        //         temp[6]=0;
        //         time+=temp[6];
        //         //cout<<temp[2]<<"\t"<<temp[0]<<"\t"<<temp[1]<<"\t"<<temp[3]<<"\t"<<temp[4]<<"\t"<<temp[5]<<endl;
        //         v[temp[2]][3]=time;
        //         v[temp[2]][4]=v[temp[2]][3]-v[temp[2]][0];
        //         v[temp[2]][5]=v[temp[2]][4]-v[temp[2]][1];
        //     }
        // }
        vector<int>p(n,0);
        vector<int>ct(n,0);
        int cnt=0;
        while(true){
            if(q.empty() && cnt>=n)break;
            else if(q.empty())time++;
            for(int i=0;i<n;i++){
                if(v[i][0]<=time && p[i]==0){
                    q.push(v[i]);
                    p[i]=1;
                    cnt++;
                }
            }
            vector<int>k=q.front();
            q.pop();
            if(k[1]>t){
                k[1]=k[1]-t;
                time=time+t;
                for(int i=0;i<n;i++){
                    if(v[i][0]<=time && p[i]==0){
                        q.push(v[i]);
                        p[i]=1;
                        cnt++;
                    }
                }
                q.push(k);
            
            }else{
                time=time+k[1];
                ct[k[3]]=time;
            }
        }
        // cout<<"pr_id\t arr\t bust\t cmplt\t tot\t wt\n";
        // for(auto it:v){
        //     cout<<it[2]<<"\t"<<it[0]<<"\t"<<it[1]<<"\t"<<it[3]<<"\t"<<it[4]<<"\t"<<it[5]<<endl;
        // }

    }
}
    