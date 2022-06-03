#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,x,i,sum,k=1,c=0;
	    cin>>m>>n>>x;
	    long long int dp[n+1][x+1];
	    memset(dp,0,sizeof(dp));
	    for(sum=1;sum<=min(x,m);sum++)
	     {
	         dp[1][sum]=1;
	     }
	    for(i=2;i<=n;i++)
	    {
	        for(sum=1;sum<=x;sum++)
	        {
	            for(k=1;k<=min(sum,m);k++)
	            {
	                dp[i][sum]+=dp[i-1][sum-k];
	            }
	        }
	    }
	   cout<<dp[n][x]<<endl; 
	}
	return 0;
}