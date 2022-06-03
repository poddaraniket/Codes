#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,i;
	cin>>t;
	int dp[100002];
	dp[0]=0;
	dp[1]=1;
	for(i=2;i<=100001;i++)
	   dp[i]=(dp[i-1]+dp[i-2])%1000000007;
	while(t--)
	 {
	     int n,i;
	     cin>>n;
	     if(n==1)
	      cout<<"1"<<endl;
	     else
	      {
	       cout<<dp[n+1]<<endl; 
	      }
	 }
	return 0;
}