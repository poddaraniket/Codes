#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,i,j,maxi=0;
	     cin>>n;
	     int a[n];
	     int dp[n]={0};
	     for(i=0;i<n;i++)
	      {
	        cin>>a[i];
	        dp[i]=a[i];
	      }
	    // dp[0]=a[0]; 
	     //cout<<"*"<<a[0]<<endl;
	     for(i=1;i<n;i++)
	      {
	          for(j=0;j<i;j++)
	           {
	               if(a[i]>a[j] && dp[j]+a[i]>dp[i])
	                dp[i]=dp[j]+a[i];
	               //else
	               //  dp[i]=a[i];
	           }
	          maxi=max(maxi,dp[i]);   
	      }
	   //  for(i=0;i<n;i++) 
	   //    cout<<dp[i]<<" ";
	     cout<<max(maxi,dp[0])<<endl; 
	 }
	return 0;
}
