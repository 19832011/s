#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"enter the no. of processes \n";
    int pn;
    cin>>pn;
    int choice;
    cout<<"enter 1 for fcfs \n enter 2 for priority \n enter 3 for roundrobin \n enter 4 for sjf \n";
      cin>>choice;
     vector<int> at(pn),bt(pn),ct(pn),tot(pn),wt(pn),pri(pn);
        vector<vector<int>>v(pn,vector<int>(7,0));
        cout<<"enter the process at \n";
        for(int i=0;i<pn;i++){
            cin>>v[i][0];
            v[i][3]=i+1;
        }
        cout<<"enter the process bt \n";
        for(int i=0;i<pn;i++){
            cin>>v[i][1];
        }
        

  
    if(choice==1){
       sort(v.begin(),v.end());
        
        for(int i=0;i<pn;i++){
            if(i==0){
                v[i][2]=v[i][0]+v[i][1];  //arrival and burst time from 2d vector
            }
            else{
                v[i][2]=v[i-1][2]+v[i][1];
            }
        v[i][4]=v[i][2]-v[i][0];
        v[i][5]=v[i][4]-v[i][1];
        }
      
        for(auto it:v){
            cout<<it[3]<<" "<<it[0]<<" "<<it[1]<<" "<<it[2]<<"  "<<it[4]<<"  "<<it[5]<<endl;
        }
    }
    else if(choice==2){
        cout<<"enter the process pri \n";
        for(int i=0;i<pn;i++){
            cin>>v[i][6];
            v[i][6]=-v[i][6];
        }

        for(int i=0;i<pn;i++){
            swap(v[i][1],v[i][6]); //2nd-priority   7th-burst
        }
        sort(v.begin(),v.end());
        for(int i=0;i<pn;i++){
            if(i==0){
                v[i][2]=v[i][0]+v[i][6];  //arrival and burst time from 2d vector
            }
            else{
                v[i][2]=v[i-1][2]+v[i][6];
            }
        v[i][4]=v[i][2]-v[i][0];
        v[i][5]=v[i][4]-v[i][6];
        }
      
        for(auto it:v){
            cout<<it[3]<<" "<<it[0]<<" "<<-it[1]<<" "<<it[6]<<" "<<it[2]<<"  "<<it[4]<<"  "<<it[5]<<endl;
        }
    }
    else if(choice==3){
        cout<<"enter time quanta\n";
        int tq;
        cin>>tq;
        queue<vector<int>>q;
        int time=0;
        vector<int>p(pn,0);
        vector<int>ct(pn+1,0);
        int cnt=0;
        while(true){
            if(q.empty() && cnt>=pn)break;
            else if(q.empty())time++;
            for(int i=0;i<pn;i++){
                if(v[i][0]<=time && p[i]==0){
                    q.push(v[i]);
                    p[i]=1;
                    cnt++;
                }
            }
            vector<int>k=q.front();
            q.pop();
            if(k[1]>tq){
                k[1]=k[1]-tq;
                time=time+tq;
                for(int i=0;i<pn;i++){
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
        for(int i=0;i<ct.size();i++){
            cout<<ct[i]<<" ";
        }
    }      
}