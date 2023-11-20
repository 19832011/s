#include<bits/stdc++.h>
using namespace std;

int main(){
    fstream inp,mdt,mnt,out;

    inp.open("input.txt",ios::in);
    mdt.open("mdt.txt",ios::in);
    mnt.open("mnt.txt",ios::in);
    out.open("out.txt",ios::out);

    map<string,int>m;
    string s;
    while(getline(mnt,s)){
        string temp="";
        for(auto i:s){
            if(i!=' '){
                temp=temp+i;
            }else{
                break;
            }
        }
        m[temp]++;

    }
    map<string,vector<string>>mp;
    while(getline(inp,s)){
        string temp="";
        for(auto i:s){
            if(i!=' '){
                temp=temp+i;
            }else{
                break;
            }
        }
        string ss=temp;
        temp="";
        bool check=0;
        if(m[ss]){
            for(auto i:s){
                if(i==' '){
                    check=1;
                }else if(i=='='){
                    // temp="";
                    break;
                }else if(i==','){
                    mp[ss].push_back(temp);
                    temp="";
                }else if(check==1){
                    temp=temp+i;
                }
            }
             mp[ss].push_back(temp);
        }
    }
    map<string,vector<string>>map;

    string a="";
    bool check=1;
    string ss="";
    while(getline(mdt,s)){
        string temp="";
        for(auto i:s){
            if(i!=' '){
                temp=temp+i;
            }else{
                break;
            }
        }

        if(temp=="MEND"){
            check=1;
        }else if(check=1){
            ss=temp;
            check=0;

        }else if(check!=1){
            temp="";
            a="";
            for(auto i:s){
                if(i){

                }
            }
        }

    }



}