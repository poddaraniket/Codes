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
        int dp[n+1];
        dp[0]=0;
        //dp[1]=1;
        for(i=1;i<=n;i++)
         dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);
        cout<<dp[n]<<endl;    
	 }
	return 0;
}
