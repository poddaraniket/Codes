#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	 string s,p;
	 cin>>s>>p;
	 int n=s.length();
      int m=p.length();
      bool dp[n+1][m+1];
      memset(dp,false,sizeof(dp));  
      //if pattern is null it will be false 
      dp[0][0]=true;  
      for(int i=1;i<=n;i++)
       {
         dp[i][0]=false;
       }  
      //if string is null we check if the pattern has '*'  
      for(int j=1;j<=m;j++)
       {
         if(p[j-1]=='*')
             dp[0][j]=dp[0][j-2];
       }
       
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
          {
              if(p[j-1]==s[i-1] || p[j-1]=='.')
                 dp[i][j]=dp[i-1][j-1];
              else if(p[j-1]=='*') 
               {
                 // will the string match without the character having start or not
                  if(dp[i][j-2]==true)
                     dp[i][j]=true;
                  else if(s[i-1]==p[j-2] || p[j-2]=='.')  // if previous character in pattern matches with current character in string or is the previous character in patter a '.' 
                  dp[i][j]=dp[i-1][j];
               }
              else
                   dp[i][j]=false;
          }
      }
    cout<<dp[n][m]<<endl; 
	return 0;
}
