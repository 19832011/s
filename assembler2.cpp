#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"

vector<vector<string>> res(100);
int idx=0;
vector<pair<string,int>> sym;
vector<pair<string,int>> lit;


vector<pair<string,string>> reg(string line)
{
    vector<pair<string,string>> ans;
    for(int i=0; i<line.size(); i++)
    {   
        string a,b;
        if(line[i]=='(')
        {
            while(line[i+1]!=',')
            {
                i++;
                a+=line[i];
            }
            i+=3;
            while (line[i]!=')')
            {
                b+=line[i];
                i++;
            }   
            ans.push_back({a,b});
        }
    }

    return ans;
}

void tables()
{
    ifstream st("sym.txt");
    ifstream lt("lit.txt");
    string line;
    while (getline(st,line))
    {
        int i=2;
        string a,b;
        while (line[i]!=' ')
        {
            a+=line[i];
            i++;
        }
        i++;
        while (i<line.size())
        {
            b+=line[i];i++;
        }
        sym.push_back({a,stoi(b)});
    }
    
    while (getline(lt,line))
    {
        int i=2;
        string a,b;
        while (line[i]!=' ')
        {
            a+=line[i];
            i++;
        }
        i++;
        while (i<line.size())
        {
            b+=line[i];i++;
        }
        lit.push_back({a,stoi(b)});
    }

    st.close();lt.close();
}


signed main()
{
    ifstream obj("ic.txt");
    ofstream out("output.txt");
    tables();
    string line;
    
    while (getline(obj,line))
    {
        // cout<<line<<endl;
        vector<pair<string,string>> in=reg(line);
        if(in[0].first=="AD") continue;
        else if(in[0].first=="IS")
        {
            // cout<<in[0].second<<endl;

            //first para
            res[idx].push_back(in[0].second);
            if(in[0].second=="00")
            {
                res[idx].push_back("00");
                res[idx].push_back("00");
                break;
            }
            //second para
            if(in.size()==2)
            {
                res[idx].push_back("00");
            }
            if(in[1].first=="RG")
            {
                res[idx].push_back(in[1].second);
            }
            else if(in[1].first=="S")
            {
                string s=to_string(sym[stoi(in[1].second)].second);
                res[idx].push_back(s);
            }
            if(in.size()==3)
            {
                // cout<<1;
                if(in[2].first=="RG")
                {
                    res[idx].push_back(in[2].second);
                }
                else if(in[2].first=="S")
                {
                    string s=to_string(sym[stoi(in[2].second)].second);
                    res[idx].push_back(s);
                }
                else if(in[2].first=="L")
                {
                    string s=to_string(lit[stoi(in[2].second)].second);
                    res[idx].push_back(s);
                } 
            }
            idx++;
        }
        else
        {
        // cout<<1;
            res[idx].push_back("00");
            res[idx].push_back("00");
            res[idx].push_back(in[1].second);
            idx++;
        }
    }
    // cout<<9;
    for (int i = 0; i < idx+1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            out<<res[i][j]<<"  ";
        }
        out<<endl;
    }
    

    obj.close();
}