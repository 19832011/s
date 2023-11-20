#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"
int lc=100,ltp=0,stp=0,ptp=0,idx=0;
vector<vector<pair<string ,string>>> ic(100);
vector<pair<string,int>> sym;
vector<pair<string,int>> lit;
vector<int> pool;

vector<string> is={"STOP","ADD","SUB","MULT","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT"};
vector<string> ad={"START","END","ORIGIN","EQU","LTORG"};
vector<string> dl={"DS","DC"};
vector<string> rg={"AREG","BREG","CREG"};
// vector<string> cc={};


int chk(string solve)
{
    int ans=0;
    string a;
    bool ch=0;
    for (auto it : solve)
    {
        if(it=='+' || it=='-')
        {
            for (int i = 0; i < sym.size(); i++)
            {
                // cout<<sym[i].first<<" "<<a<<endl;
                if(sym[i].first==a)
                {
                    ans+=sym[i].second;
                    break;
                }
            }
            a="";
            if(it=='+') ch=1;
        }
        a+=it;
    }
    int x=stoi(a);
    if(ch) ans+=x;
    else ans-=x;
    return ans;
}

vector<string> reg(string line)
{
    vector<string> ans;
    string s="";
    bool flag =1;
    for(auto it : line)
    {
        if(it==' ')
        {
            if(s.size() || flag)ans.push_back(s);
            s="";
            flag=0;
        }
        else s+=it;
    }
    ans.push_back(s);
    return ans;
}

string con(int i)
{
    if(i<10) return "0"+to_string(i);
    else return to_string(i);
}


void ispar(vector<string> in,int x)
{
    string t=in[x];
    if(x==2)
    {   
        bool cj=0;
        for (int i=0; i<rg.size(); i++)
        {
            if(rg[i]==t)
            {
                ic[idx].push_back({"RG",con(i+1)});
                cj=1;
            }
        }       
        if(!cj)
        {
            for (int i = 0; i < sym.size(); i++)
            {
                if(sym[i].first==t)
                {
                    ic[idx].push_back({"S",con(i)});
                }
            }
        }
    }
    else
    {
        if(t.find("=")!=string::npos)
        {
            lit.push_back({t.substr(2,t.size()-3),-1});
            ic[idx].push_back({"L",con(lit.size()-1)});
        }
        else
        {
            bool dch=0;
            int ind;
            for (int i = 0; i < sym.size(); i++)
            {
                if(sym[i].first==t)
                {
                    dch=1;ind=i;break;
                }
            }
            if(!dch) {sym.push_back({t,-1});ind=sym.size()-1;}
            ic[idx].push_back({"S",con(ind)});
        }
    }
}

void filewriter()
{
    ofstream op("ic.txt");
    ofstream pt("pool.txt");
    ofstream st("symbol.txt");
    ofstream lt("literal.txt");
    for (int i = 0; i < idx+1; i++)
    {
        for (int j = 0; j < ic[i].size(); j++)
        {
            op<<"("<<ic[i][j].first<<", "<<ic[i][j].second<<") ";
        }
        op<<endl;
    }
    
    for (int i = 0; i < sym.size(); i++)
    {
        st<<i<<" "<<sym[i].first<<" "<<sym[i].second<<endl;
    }
    
    for (int i = 0; i < lit.size(); i++)
    {
        lt<<i<<" "<<lit[i].first<<" "<<lit[i].second<<endl;
    }

    for (int i = 0; i < pool.size(); i++)
    {
        pt<<i<<" "<<pool[i]<<" "<<endl;
    }
    op.close();
    pt.close();
    lt.close();
    st.close();
}


signed main()
{
    
    ifstream obj("input.txt");
    string line;
    getline(obj,line);
    vector<string> in=reg(line);
    ic[idx].push_back({"AD","01"});
    if(in.size()>2)
    {
        // cout<<"sit";
        lc=stoi(in[2]);
        ic[idx].push_back({"C",to_string(lc)});
    }
    idx++;
    while(getline(obj,line))
    {
        vector<string> in=reg(line);
        //check for symbol
        if(in[0]!="" && in[1]!="EQU") 
        {
            bool f=0;
            for (int i = 0; i < sym.size(); i++)
            {
                if(sym[i].first==in[0] && sym[i].second!=-1)
                {
                    cout<<"error twice declaration";
                    goto end;
                }
                if(sym[i].first==in[0])
                {
                    sym[i].second=lc;
                    f=1;
                } 
            }
            if(!f)  sym.push_back({in[0],lc});
        } 
        //opcode checking
        if(in[1]=="LTORG" || in[1]=="END")
        {
            bool pl=0;
            for (int i = 0; i < lit.size(); i++)
            {
                if(lit[i].second==-1)
                {
                    //update pool table;
                    if(!pl)
                    {
                        pool.push_back(i);
                        pl=1;
                    }
                    lit[i].second=lc;
                    if(in[1]=="LTORG")
                        ic[idx].push_back({"AD","05"});
                    ic[idx].push_back({"DL","02"});
                    ic[idx].push_back({"C",lit[i].first});
                    idx++;lc++;
                    
                }
            }
            //if end then
            if(in[1]=="END")
            {
                ic[idx].push_back({"AD","02"});
                idx++;
            }
        }

        else if(in[1]=="ORIGIN")
        {
            string solve=in[2];
            int ans=chk(solve);
            lc=ans;
            ic[idx].push_back({"AD","03"});
            ic[idx].push_back({"C",to_string(ans)});
            idx++;
        }
        else if(in[1]=="EQU")
        {
            string solve=in[2];
            int ans=chk(solve);
            string ap=in[0];
            bool h=0;
            for (int i = 0; i < sym.size(); i++)
            {
                if(sym[i].first==ap)
                {
                    sym[i].second=ans;
                    h=1;
                }
            }
            if(!h) sym.push_back({ap,ans});
            ic[idx].push_back({"AD","04"});
            ic[idx].push_back({"C",con(ans)});
            idx++;
        }
        else if(in[1]=="DS")
        {
            ic[idx].push_back({"DL","01"});
            ic[idx].push_back({"C",(in[2])});
            idx++;lc+=stoi(in[2]);
        }
        else if(in[1]=="DC")
        {
            ic[idx].push_back({"DL","02"});
            ic[idx].push_back({"C",(in[2])});
            idx++;lc++;
        }
        else
        {
            int ind=0;
            for(int i=0; i<11; i++)
            {
                if(in[1]==is[i])
                {
                    ic[idx].push_back({"IS",con(i)});
                    ind=i;
                    break;
                }
            }
           if(ind>0)
           {
                ispar(in,2);
           }
           if(ind>0 && ind<10)
           {
                ispar(in,3);
           }
            idx++;lc++;
        }
    }

    filewriter();
    end:{}
    obj.close();
 return 0;
}