#include<bits/stdc++.h>
using namespace std;

int main(){
    fstream ic , mc , ltab , stab;
    ic.open("IC.txt" , ios::in);
    ltab.open("LITTAB.txt" , ios::in);
    stab.open("SYMTAB.txt" , ios::in);
    mc.open("MachineCode.txt" , ios::out);

    vector<int> st , lt;

    string sa , sb;
    while(getline(stab , sa)){
        string temp = "";
        int x = sa.size();
        for(int i=x-1 ; i>=0 ; --i){
            if(sa[i] == ' ') break;
            temp += sa[i];
        }
        reverse(temp.begin() , temp.end());
        st.push_back(stoi(temp));
    }


    while(getline(ltab , sb)){
        string temp = "";
        int x = sb.size();
        for(int i=x-1 ; i>=0 ; --i){
            if(sb[i] == ' ') break;
            temp += sb[i];
        }
        reverse(temp.begin() , temp.end());
        lt.push_back(stoi(temp));
    }


    string line;
    while(getline(ic , line)){
        string temp = "" , str="";
        int flag = 0 , last = 0;
        for(auto ch : line){
            if(ch == '('){
                temp = "";
                str = "";
            }
            else if(ch == ','){
                if(temp == "AD"){
                    flag = 1;
                    break;
                }
                str = temp;
                temp = "";
                continue;
            }
            else if(ch == ')'){
                if(temp == "00"){
                    last = 1;
                    break;
                }
                if(str != "S" and str != "L"){
                    if(str == "DL") mc << "00 00 ";
                    else mc << temp << " ";
                }
                else if(str == "S"){
                    int x = temp[1] - '0';
                    mc << st[x];
                }
                else if(str == "L"){
                    int x = temp[0] - '0';
                    mc << lt[x];
                }
                str = "";
            }else temp += ch;


        }
        if(flag == 1) continue;
        if(last == 1) break;
        mc << endl;
    }

}