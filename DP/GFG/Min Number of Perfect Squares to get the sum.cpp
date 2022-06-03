#include <bits/stdc++.h>
using namespace std;

int numSquares(int n)
{
      vector<int> v;
      for(int i=n;i>=1;i--)
        {
          if(ceil(sqrt(i))==floor(sqrt(i)))
            v.push_back(i);
        }
    //  for(int i=0;i<v.size();i++)
    //   cout<<v[i]<<" ";
    //  cout<<endl; 
      int dp[n+1];
      for(int i=1;i<=n;i++)
          dp[i]=100000000;
      dp[0]=0;  
      for(int i=0;i<v.size();i++)
      {
          for(int j=1;j<=n;j++)
          {
              if(v[i]<=j)
               {
                  dp[j]=min(dp[j-v[i]]+1,dp[j]);
               }        
          }
      }
    //   for(int i=0;i<=n;i++)
    //   cout<<dp[i]<<" ";
    //   cout<<endl; 
      return dp[n];  
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	cout<<numSquares(n)<<endl;
	return 0;
}
