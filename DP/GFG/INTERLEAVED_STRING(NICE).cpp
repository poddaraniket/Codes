#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
       string a,b,s;
       cin>>a>>b>>s;
       int i,j;
       int n=a.length();
       int m=b.length();
       bool dp[n+1][m+1];
       dp[0][0]=true;
       for(i=1;i<=m;i++)
        {
            if(s[i-1]==b[i-1])
             {
                dp[0][i]=dp[0][i-1];
             }
            else
              dp[0][i]=false;
        }
       for(i=1;i<=n;i++)
        {
            if(s[i-1]==a[i-1])
             {
                dp[i][0]=dp[i-1][0];
             }
            else
              dp[i][0]=false;
        }
       for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
             {
                 int t=i+j;
                 if(b[j-1]==s[t-1])
                  {
                    dp[i][j]=dp[i][j-1];
                    if(a[i-1]==s[t-1])  
                        dp[i][j]=dp[i-1][j]||dp[i][j-1];
                      
                        
                      //cout<<"*"<<i<<" "<<j<<endl;
                  }
                 else if(a[i-1]==s[t-1])
                  {
                      dp[i][j]=dp[i-1][j];
                  }
                 else
                   dp[i][j]=false;
             }
        }
      if(dp[n][m])    
       cout<<"1"<<endl;
      else
       cout<<"0"<<endl;
	 }
	return 0;
}
