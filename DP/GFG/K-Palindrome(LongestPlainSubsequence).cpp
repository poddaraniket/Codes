#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function*/
bool is_k_palin(string s,int k)
{
//Your code here
  int n=s.length();
  int dp[n][n];
  for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
        dp[i][j]=0;
   }
  for(int i=0;i<n;i++)
   {
      dp[i][i]=1;
   }
  for(int k=2;k<=n;k++)
    {
       for(int i=0;i<=n-k;i++)
        {
            int j=i+k-1;
            if(s[i]==s[j])
             {
                dp[i][j]=dp[i+1][j-1]+2; 
             }
            else
             dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
   if(s.length()-dp[0][n-1]<=k)
    return true;
  return false;    
    
}