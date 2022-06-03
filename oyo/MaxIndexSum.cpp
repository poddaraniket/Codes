#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n;
	     cin>>n;
	     int arr[n+1];
	     arr[0]=0;
	     for(int i=1;i<=n;i++)
	      {
	          cin>>arr[i];
	      }
	     int sum;
	     cin>>sum;
	     int dp[n+1][sum+1];
	     memset(dp,0,sizeof(dp));
	     for(int i=0;i<=sum;i++)
	      dp[i][0]=0;
	     for(int i=0;i<=n;i++)
	      dp[0][i]=0; 
	     for(int i=1;i<=n;i++)
	      {
	          for(int j=1;j<=sum;j++)
	           {
	               if(i<=j)
	                {
	                    dp[i][j]=max(dp[i-1][j],dp[i][j-i]+arr[i]);
	                }
	               else
	                {
	                    dp[i][j]=dp[i-1][j];
	                }
	           }
	      }
	   //  for(int i=0;i<=n;i++)
	   //   {
	   //       for(int j=0;j<=sum;j++)
	   //        cout<<dp[i][j]<<" ";
	   //       cout<<endl;    
	   //   }
	     cout<<dp[n][sum]<<endl; 
	 }
	return 0;
}
