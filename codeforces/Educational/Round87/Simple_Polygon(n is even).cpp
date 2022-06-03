//Initial Template for C++
 
#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
 
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        float ans;
        cin>>n;
        //cout<<n;
        float teta=(360.0/(2*n))/2.0;
        //cout<<teta<<endl;
        float radian=teta*(pi/180);
        //cout<<radian<<endl;
        ans=(1/(2*tan(radian)));
        cout<<fixed<<setprecision(9)<<ans*2<<endl; 
    }
}  // } Driver Code Ends