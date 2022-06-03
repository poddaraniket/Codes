#include <bits/stdc++.h>
using namespace std;

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
	    int len=sent.length();
	    bool dp[len][len];
	    for(l=1;l<=sent.length();l++)
	    {
	        for(i=0;i<=sent.length()-l;i++)
	        {
	            j=(i+l)-1;
	            c=0;
	            for(int k=0;k<v.size();k++)
	             {
	                // cout<<sent.substr(i,l)<<endl;
	                 if(sent.substr(i,l)==v[k])
	                  {
	                      dp[i][j]=true;
	                      c=1;
	                      break;
	                  }
	             }
	            if(c==1)
	             continue;
	            else
	             {
	                 dp[i][j]=false;
	                 for(d=i;d<j;d++)
	                  {
	                    if(dp[i][d] && dp[d+1][j])
	                    {
	                     dp[i][j]=true;
	                     break;
	                    }
	                    else
	                     dp[i][j]=false;
	                  }
	             }
	        }
	    }
	   cout<<dp[0][len-1]<<endl;
	}
	return 0;
}
