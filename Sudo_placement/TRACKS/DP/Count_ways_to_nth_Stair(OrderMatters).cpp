#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long countWays(int);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin>>m;
        cout<<countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends


// function to count ways to reach mth stair
long long countWays(int m){
    // your code here
    int i;
    long long dp[m+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(i=3;i<=m;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%1000000007;
    }
    return dp[m];
}
