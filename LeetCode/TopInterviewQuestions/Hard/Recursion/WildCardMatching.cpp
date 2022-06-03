/*
TC->O(NM)
? -> dp[i-1][j-1]
ch -> if s==p ? dp[i-1][j-1] : false;
* -> check that till pev pattern part if we can make the string so far or till anywhere, if yes then till wherever it bcam after that till here * will make it (>=0)


                     -  b  a  *  a  ?
                 -   T  F  F  F  F  F
                 b   F  T  F  F  F  F
                 a   F  F  T  T  F  F
                 a   F  F  F  T  T  F
                 a   F  F  F  T  T  T
                 b   F  F  F  T  F  T
                 a   F  F  F  T  T  F
                 b   F  F  F  T  F  T
                     |  |  |  |  |  |  
                    \|/\|/\|/\|/\|/\|/
            DUMMY[]= T  T  T  T  T  T   
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
        bool dummy[n+1];
        dummy[0]=true;;
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*')
               dp[0][j]=dp[0][j-1];
            else{
                dp[0][j]=false;
            }
            dummy[j]=dp[0][j];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]>='a' && p[j-1]<='z')
                    dp[i][j]=(s[i-1]==p[j-1]) ? dp[i-1][j-1] : false;
                else{
                    dp[i][j]=dummy[j-1];

                    // save time-------------------------- 
                    // for(int k=0;k<=i;k++){
                    //     if(dp[k][j-1]){
                    //         dp[i][j]=true;
                    //         break;
                    //     }
                    // }
                }
                if(dp[i][j])
                   dummy[j]=true; 
            }
        }
        return dp[m][n];
    }
};