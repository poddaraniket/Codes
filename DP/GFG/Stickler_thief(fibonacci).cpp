#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,i;
	     cin>>n;
	     int a[n],dp[n];
	     for(i=0;i<n;i++)
	      {
	        cin>>a[i];   
	      }
	     if(n==1)
	      cout<<a[0]<<endl;
	     else if(n==2)
	      cout<<max(a[0],a[1])<<endl;
	     else
	       {
	           dp[0]=a[0];
	           dp[1]=max(a[0],a[1]);
	           for(i=2;i<n;i++)
	            {
	                dp[i]=max(dp[i-2]+a[i],dp[i-1]);
	            }
	           cout<<dp[n-1]<<endl; 
	       }
	 }
	return 0;
}
