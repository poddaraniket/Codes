#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
       int n,m;
	cin>>n;
	int val[2]={1,2}; 
	m=2;
	//for(int i=0;i<)
	int dp[n+1][m];
	for(int i=0;i<m;i++)
	 dp[0][i]=1;
	for(int i=1;i<=n;i++)
	 {
	   for(int j=0;j<m;j++)
	    {
	        int x=0,y=0;
	        if(i>=val[j])
	         {
	             x=dp[i-val[j]][j];
	         }
	        if(j>=1)
	         y=dp[i][j-1];
	        dp[i][j]=x+y; 
	    }
	 }
	cout<<dp[n][m-1]<<endl; 
	 }
	return 0;
}
