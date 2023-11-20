#include<bits/stdc++.h>
using namespace std;

int main(){
    int frames_n,page_n;
    cout<<"enter the number of frames and pages\n";
    cin>>frames_n>>page_n;
    vector<int>page(page_n);
    cout<<"enter the pages \n";
    for(int i=0;i<page_n;i++) cin>>page[i];
    vector<int>frames(frames_n,-1);
    int count=0,hit=0,fault=0;
    int replace_ind=0;

    frames[0]=page[0];
    count++;
    fault++;

    int choice;
    cout<<"enter 1 for fifo \n enter 2 for optimal \n enter 3 for lru \n";
    cin>>choice;
    while(count<page_n){
        int arr[frames_n]={0};
        bool found=0;
        for(int i=0;i<frames_n;i++){
            if(frames[i]==page[count]){
                
                found=1;
                break;
            }
        }
        if(found){
            hit++;
            count++;
        }
        else{
            fault++;
            bool emptyness=0;
            for(int i=0;i<frames_n;i++){
                if(frames[i]==-1){
                    frames[i]=page[count];
                    //cout<<frames[i]<<" "<<i<<" "<<page[count]<<" "<<count<<endl;
                    emptyness=1;
                    count++;
                    break;
                }
            }
            if(!emptyness){

                switch (choice)
                {
                case 1:
                    frames[replace_ind]=page[count];
                    
                    // cout<<frames[replace_ind]<<" "<<replace_ind<<" "<<page[count]<<" "<<count<<endl;
                    // for(auto it:frames)cout<<it<<" ";
                    // cout<<endl;
                    // cout<<page[count]<<endl;
                    //for(auto it:page)cout<<it<<" ";
                    replace_ind=(replace_ind+1)%frames_n;
                    count++;
                    break;
                case 2:
                    
                    for(int i=0;i<frames_n;i++){
                        for(int j=count;j<page_n;j++){
                            if(page[j]==frames[i]){
                                arr[i]=j;
                                break;
                            }
                        }
                    }
                    int temp1;
                    temp1=INT_MIN;
                    for(int i=0;i<frames_n;i++){
                        if(arr[i]>temp1){
                            temp1=arr[i];
                            replace_ind=i;
                        }
                    }
                    frames[replace_ind]=page[count];
                    //cout<<frames[replace_ind]<<" "<<replace_ind<<" "<<page[count]<<" "<<count<<endl;
                    count++;
                    replace_ind=0;
                    break;
                case 3:
                    
                    for(int i=0;i<frames_n;i++){
                        for(int j=count-1;j>=0;j--){
                            if(page[j]==frames[i]){
                                arr[i]=j;
                                break;
                            }
                        }
                    }
                    int temp2;
                    temp2=INT_MAX;
                    for(int i=0;i<frames_n;i++){
                        if(arr[i]<temp2){
                            temp2=arr[i];
                            replace_ind=i;
                        }
                    }
                    frames[replace_ind]=page[count];
                    //cout<<frames[replace_ind]<<" "<<replace_ind<<" "<<page[count]<<" "<<count<<endl;
                    count++;
                    replace_ind=0;
                    break;
                default:
                    cout<<"invalid input";
                    break;
                }
                
            }
        }
    }
    cout<<"hit \t - "<<hit<<endl<<"fault \t - "<<fault<<endl;
}