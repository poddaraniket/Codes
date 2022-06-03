//Initial Template for C++
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len=s.length();
        int find[4];
        memset(find,-1,sizeof(find));
        //cout<<"*"<<find[2]<<endl;
        int mini=100000000;
        for(int i=0;i<len;i++)
        {
            find[s[i]-'0']=i;
            //cout<<find[s[i]-'0']<<endl;
            if(find[1]!=-1 && find[2]!=-1 && find[3]!=-1)
             {
                // cout<<max(max(find[1],find[2]),find[3])<<endl;
                // cout<<min(min(find[1],find[2]),find[3])<<endl;
                int c=(max(max(find[1],find[2]),find[3])-min(min(find[1],find[2]),find[3]))+1;
                mini=min(c,mini);
             }
        }
       if(mini==100000000) 
        cout<<"0"<<endl;
       else
        cout<<mini<<endl;
    }
}  // } Driver Code Ends