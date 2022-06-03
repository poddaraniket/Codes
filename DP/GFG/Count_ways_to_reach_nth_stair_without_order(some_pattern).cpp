#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
       int n,i,p=0;
       cin>>n;
       int dp[n+2];
       for(i=0;i<=n;i+=2)
        {
            p++;
            dp[i]=p;
            dp[i+1]=dp[i];
        }
      cout<<dp[n]<<endl;
	 }
	return 0;
}
