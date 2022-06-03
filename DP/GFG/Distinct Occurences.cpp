#include <bits/stdc++.h>
using namespace std;
 
int subsequenceCount(string S, string T);

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		cout<<subsequenceCount(s,tt)<<endl;
		
		
	}
  
}// } Driver Code Ends


/*You are required to complete this method*/


int subsequenceCount(string S, string T)
{
  //Your code here
  int m=S.length();
  int n=T.length();
  int dp[n+1][m+1];
  dp[0][0]=1;
  for(int i=0;i<=n;i++)
   {
     dp[i][0]=0;  
   }
  for(int j=0;j<=m;j++)
   {
     dp[0][j]=1;  
   }
  for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
        {
           if(T[i-1]==S[j-1])
            {
                dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%1000000007;
            }
           else
            dp[i][j]=dp[i][j-1];
        }
   }
   return dp[n][m];
}
 
