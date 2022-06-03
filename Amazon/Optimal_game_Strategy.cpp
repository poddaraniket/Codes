#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	     cin>>a[i];
	    int dp[n][n];
	    for(int i=0;i<n;i++)
	     {
	         for(int j=0;j<n;j++)
	          dp[i][j]=0;
	     }
	    for(int gap=0;gap<n;gap++)
	     {
	         for(int i=0;i<n-gap;i++)
	          {
	              int j=gap+i;
	              if(i==j)
	               dp[i][j]=a[i];
	              else
	               {
	                   dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));
	               }
	          }
	     }
	    cout<<dp[0][n-1]<<endl; 
	}
	return 0;
}