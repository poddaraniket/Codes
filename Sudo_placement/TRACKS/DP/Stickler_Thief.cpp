#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends


// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n)
{
    // Your code here
    ll i;
    ll dp[n];
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(i=2;i<n;i++)
    {
       dp[i]=max(dp[i-2]+arr[i],dp[i-1]); 
    }
    return dp[n-1];
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends