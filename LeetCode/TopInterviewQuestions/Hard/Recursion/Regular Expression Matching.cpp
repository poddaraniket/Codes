/*
TC->O(NM)
i->s && j->p

* -> means it makes the previous character dynmaic from 0 to inf times
. -> single character match

s -> mississippi
p -> mis*i.*p*i 

eg -> mis/mis* -> mis/miss*(s*->[s>=1]){dp[i-1][j]} & mis/mi(s*->null){dp[i][j-2]}

cancel out s with s b4 s* in first to reduce the comp as in dp we can't check for more than exist [comp for(mis/mis*) bt made it (mis/miss*[extra here])]  

* -> 

*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        bool dp[m+1][n+1];
        dp[0][0]=true;
        for(int i=1;i<=m;i++)
            dp[i][0]=false;
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*')
               dp[0][j]=dp[0][j-2];
            else
                dp[0][j]=false;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]>='a' && p[j-1]<='z')
                    dp[i][j]=(s[i-1]==p[j-1]) ? dp[i-1][j-1] : false;
                else{
                    dp[i][j]=dp[i][j-2];
                    if(p[j-2]==s[i-1] || p[j-2]=='.') 
                     dp[i][j]=dp[i][j] || dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};