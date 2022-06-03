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
       dp[1]=1;
       if(n==1)
        cout<<"1"<<endl;
       for(i=2;i<=n;i++)
        {
            if(i%2==0)
             dp[i]=min(dp[i/2],dp[i-1])+1;
            else
             dp[i]=dp[i-1]+1;
        }
      cout<<dp[n]<<endl;
	 }
	return 0;
}
