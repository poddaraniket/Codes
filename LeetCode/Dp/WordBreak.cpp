class Solution {
public:
    
    bool check(string s,vector<string>& wordDict)
    {
        for(int i=0;i<wordDict.size();i++)
        {
            if(wordDict[i]==s)
                return true;
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int dp[s.length()][s.length()];
        memset(dp,false,sizeof(dp));
        for(int k=1;k<=s.length();k++)
        {
            for(int i=0;i<=s.length()-k;i++)
            {
                int j=i+k-1;
                if(check(s.substr(i,k),wordDict))
                {
                    dp[i][j]=true;
                }
                else if(i!=j)
                {
                    for(int p=i;p<j;p++)
                    {
                        dp[i][j]=dp[i][j] || (dp[i][p] && dp[p+1][j]);
                    }
                }
            }
        }
       return dp[0][s.length()-1]; 
    }
};