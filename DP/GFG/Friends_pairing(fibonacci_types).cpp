#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b) 
{ 
    return ((a.second.first*a.second.second) > (b.second.first*b.second.second)); 
} 

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	   int n,i,t;
	   cin>>n;
	   long long int dp[n+1];
	   for(i=0;i<=n;i++)
	    {
	      if(i<=2)
	       dp[i]=i;
	      else
	       dp[i]=((((i-1)*dp[i-2])%1000000007)+dp[i-1])%1000000007;
	    }
	   cout<<dp[n]<<endl; 
	 }
	return 0;
}
