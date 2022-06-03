
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	 {
	     //int dp[1001]={0};
	     long long int n,s=0,i=0,l,r,mod;
	     cin>>n>>l>>r;
	     while(n>0)
	      {
	        ++i;
	        mod=n%2;
	        if(i>=l && i<=r)
	         {
	            if(mod==1)
	             mod=0;
	            else
	             mod=1;
	         }
	        s+=(pow(2,i-1)*mod); 
	        n/=2;
	      }
	    cout<<s<<endl; 
	 }
}