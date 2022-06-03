string longestPalindrome(string s) {
       int frst=0,maxi=1; 
       int n=s.length();
       int dp[n][n];
       memset(dp,0,sizeof(dp)); 
       for(int i=0;i<n;i++)
        {
           dp[i][i]=1;
        }
       for(int gap=2;gap<=n;gap++)
       {
           for(int i=0;i<=n-gap;i++)
           {
               int j=gap+i-1;
               if(s[i]==s[j])
                {
                  if(gap==2)
                  {
                      dp[i][j]=1;
                  }
                 else
                  {
                     dp[i][j]=dp[i+1][j-1];   
                  }
                 if(dp[i][j]==1 && maxi<(j-i+1))
                 {
                     maxi=j-i+1;
                     frst=i;
                 }
                }
           }
       }
      return s.substr(frst,maxi);  
    }