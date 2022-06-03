#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int m,n,i,j;
	     cin>>m>>n;
	     int a[n];
	     for(i=0;i<n;i++)
	      cin>>a[i];
	     int dp[m+1];
	     for(i=0;i<=m;i++)
	      dp[i]=1000000;
	     dp[0]=0;
	     for(i=0;i<n;i++)
	      {
	          for(j=1;j<=m;j++)
	           {
	               if(a[i]<=j)
	                dp[j]=min(dp[j-a[i]]+1,dp[j]);
	           }
	      }
            if(n==1 && a[0]==1)
              cout<<dp[m]<<endl;
            else
             {
	          if(dp[m]>=1000000)
	           cout<<"-1"<<endl;
	          else 
	           cout<<dp[m]<<endl;
	         }
	 }
	return 0;
}
