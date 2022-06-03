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
        if(n<4)
         cout<<"1"<<endl;
        else if(n==4)
         cout<<"2"<<endl;
        else
        {
        long long int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        dp[3]=1;
        dp[4]=2;
        for(i=5;i<=n;i++)
         {
            dp[i]=dp[i-1]+dp[i-4]; 
         }
        cout<<dp[n]<<endl;
        }
	 }
	return 0;
}
