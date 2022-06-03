#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	long long int t,k,num,num1,i;
	long long int dp[100001];
	for(i=0;i<=100000;i++)
	 dp[i]=1;
	cin>>t>>k;
	//int a[t][2];
	for(i=1;i<=100000;i++)
	{
	    dp[i]=dp[i-1];
	    if(i>=k)
	      dp[i]=(dp[i]+dp[i-k])%1000000007;
	}
	for(i=1;i<=100000;i++)
	 dp[i]=(dp[i]+dp[i-1])%1000000007;
	for(i=0;i<t;i++)
	 {
	     cin>>num>>num1;
	     cout<<(dp[num1]-dp[num-1]+1000000007)%1000000007<<endl;
	 }
	return 0;
}
