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
	   
	   string patt,str;
	   cin>>patt>>str;
	   int i,j; 
	   int m=patt.length();
	   int n=str.length();
	   bool dp[n+1][m+1];
	    dp[0][0]=true; 
	   for(i=1;i<=m;i++)
	    {
	     if(patt[i-1]!='*')   
	       dp[0][i]=false;
	      else
	       dp[0][i]=dp[0][i-1];
	    }
	   for(i=1;i<=n;i++)
	    dp[i][0]=false;
	   for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=m;j++)
	         {
	             if(str[i-1]==patt[j-1] || patt[j-1]=='?')
	              dp[i][j]=dp[i-1][j-1];
	             else if(patt[j-1]=='*')
	              dp[i][j]=dp[i-1][j]||dp[i][j-1];
	             else
	              dp[i][j]=false;
	              
	         }
	    }
	   //for(i=0;i<=n;i++)
	   // {
	   //     for(j=0;j<=m;j++)
	   //      cout<<dp[i][j]<<" ";
	   //     cout<<endl; 
	   // }
	   cout<<dp[n][m]<<endl; 
	 }
	return 0;
}
