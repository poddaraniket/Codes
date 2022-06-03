//Initial Template for C++
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a<=b)
         cout<<b<<endl;
        else
         {
            if(c<=d)
             cout<<"-1"<<endl;
            else
             {
                double up=a-b;
                double down=c-d;
                ll rem=ceil(up/down);
                cout<<b+(rem*c)<<endl;
             }
         }
    }
}  // } Driver Code Ends