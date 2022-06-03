class Solution {
public:
    int numDecodings(string s) {
       int dp[s.length()+1];
       dp[0]=1;
       if(s[0]=='0')
         return 0;
        dp[1]=1;
        for(int i=2;i<=s.length();i++)
        {
            int c1=0,c2=0;
            if(s[i-1]!='0')
             {
                c1=dp[i-1];
             }
            if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7'))
             {
                c2=dp[i-2];
             }
            dp[i]=c1+c2;       
        }
       return dp[s.length()]; 
    }
};