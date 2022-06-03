#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	 {
	     cin>>arr[i];
	 }
	
	int dp[k+1][n];
	for(int i=0;i<n;i++)
	{
	    dp[0][i]=0;
	}
	
	for(int i=0;i<=k;i++)
	{
	    dp[i][0]=0;
	}
	for(int i=1;i<=k;i++)
	 {
	     int maxdiff=-arr[0];
	     for(int j=1;j<n;j++)
	      {
	          dp[i][j]=max(dp[i][j-1],arr[j]+maxdiff);
	          maxdiff=max(maxdiff,dp[i-1][j]-arr[j]);
	          
	      }
	 }
	cout<<dp[k][n-1]<<endl; 
	return 0;
}
