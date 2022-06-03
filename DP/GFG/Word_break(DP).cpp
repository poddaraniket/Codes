#include <bits/stdc++.h>
using namespace std;

bool check(string s,vector<string> v)
{
    for(int i=0;i<v.size();i++)
     {
         if(s==v[i])
          return true;
     }
    return false; 
}

bool possible(string sent,vector<string> v)
{
   int n=sent.length();
   int dp[n][n];
   memset(dp,0,sizeof(dp));
   for(int k=1;k<=n;k++)
   {
       for(int i=0;i<=n-k;i++)
       {
           int j=i+k-1;
           if(i==j)
            {
             if(check(sent.substr(i,k),v))
              {
                dp[i][j]=1;
              }
            }
           else
            {
                if(check(sent.substr(i,k),v))
                 {
                    dp[i][j]=1;
                 }
                else
                 {
                     for(int p=i;p<j;p++)
                      {
                        if(dp[i][j]!=1)
                         dp[i][j]=dp[i][p] && dp[p+1][j];
                      }
                 }
            }
        }
    }
    return dp[0][n-1];
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,l,j,d,c=0;
	    cin>>n;
	    vector<string> v;
	    for(i=0;i<n;i++)
	    {
	     string word;
	     cin>>word;
	     v.push_back(word);
	    }
	    string sent;
	    cin>>sent;
	    cout<<possible(sent,v)<<endl;
	}
	return 0;
}
