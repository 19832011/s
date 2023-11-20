
#include<bits/stdc++.h>
using namespace std;

int main(){
    int p_size,m_size;
    cout<<"enter the no. of processes and memory blocks \n";
    cin>>p_size>>m_size;
    int p[p_size],m[m_size];
    cout<<"\nenter the processes \n";
    for(int i=0;i<p_size;i++){
        cin>>p[i];
    }
    cout<<"\n enter the memory block sizes \n";
    for(int i=0;i<m_size;i++){
        cin>>m[i];
    }
    int choice;
    cout<<"\n enter 1 for bestfit \n enter 2 for wrostfit \n enter 3 for nextfit \n enter 4 for firstfit \n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        
        for(int i=0;i<p_size;i++){
            bool fit=0;
            int ind=-1;
            for(int j=0;j<m_size;j++){
                if(m[j]>=p[i]){
                    fit=1;
                    if(ind==-1)ind=j;
                    if(m[j]<m[ind])ind=j;
                }
            }
            
            if(fit){
                m[ind]-=p[i];
                cout<<"\n process "<<i+1<<" size "<<p[i]<<" in block "<<ind+1<< " with new size "<<m[ind]<<endl;
            }
            else cout<<"\n process "<<i+1<<" size "<<p[i]<<" could not fit in memory blocks \n";
        }

        break;
    case 2:

        for(int i=0;i<p_size;i++){
            bool fit=0;
            int ind=-1;
            for(int j=0;j<m_size;j++){
                if(m[j]>=p[i]){
                    fit=1;
                    if(ind==-1)ind=j;
                    if(m[j]>m[ind])ind=j;
                }
            }
            if(fit){
                m[ind]-=p[i];
                cout<<"process "<<i+1<<" size "<<p[i]<<" in block "<<ind+1<< " with new size "<<m[ind]<<endl;
            }
            else cout<<"process "<<i+1<<" size "<<p[i]<<" could not fit in memory blocks \n";
        }

        break;
    case 4:

        for(int i=0;i<p_size;i++){
            bool fit=0;
            int ind=-1;
            for(int j=0;j<m_size;j++){
                if(m[j]>=p[i]){
                    ind=j;
                    break;
                }

            }
            if(ind==-1)cout<<"process "<<i+1<<" size "<<p[i]<<" could not fit in memory blocks \n";
            else{
                m[ind]-=p[i];
                cout<<"process "<<i+1<<" size "<<p[i]<<" in block "<<ind+1<< " with new size "<<m[ind]<<endl;
            }
        }        

        break;
    case 3:

        int j;
        j=0;
        for(int i=0;i<p_size;i++){
            bool fit=0;
            int ind=-1;
            
            while(j!=m_size  ){
                if(m[j]>=p[i]){
                    ind=j;
                    break;
                }
                j++;
                
            }
            if(ind==-1)cout<<"process "<<i+1<<" size "<<p[i]<<" could not fit in memory blocks \n";
            else{
                m[ind]-=p[i];
                cout<<"process "<<i+1<<" size "<<p[i]<<" in block "<<ind+1<< " with new size "<<m[ind]<<endl;
            }
        }

        break;
    default:
    cout<<"Invalid choice\n";
        break;
    }

}
// 100 500 200 300 600
// 212 417 112 426