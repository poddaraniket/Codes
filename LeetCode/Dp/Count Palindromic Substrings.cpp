class Solution {
public:
    int countSubstrings(string s) {
       int n=s.length(); 
       int dp[n][n];
       bool p[n][n];
       memset(p,false,sizeof(p));
       memset(dp,0,sizeof(dp));
       for(int i=0;i<n;i++)
        {
           dp[i][i]=1;
           p[i][i]=true;
        }
       for(int gap=1;gap<n;gap++)
       {
           for(int i=0;i<n-gap;i++)
           {
               int j=i+gap;
               if(s[i]==s[j])
               {
                   if(gap==1)
                       p[i][j]=true;
                   else
                   {
                       if(p[i+1][j-1])
                         p[i][j]=true;
                   }     
               }
               if(p[i][j])
                {
                   dp[i][j]=dp[i+1][j]+dp[i][j-1]+1-dp[i+1][j-1];
                }
               else
                {
                  dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];  
                } 
           }
       }
      return dp[0][n-1];  
    }
};