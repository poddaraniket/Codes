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
	   int n,i,j;
	   cin>>n;
	   int a[n];
	   for(i=0;i<n;i++)
	    cin>>a[i];
	   int dp[n+1]={0};
	   for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	         {
	             if(i<=j)
	              {
	                  dp[j]=max(dp[j-i]+a[i-1],dp[j]);
	              }
	         }
	    }
	   cout<<dp[n]<<endl; 
	 }
	return 0;
}
