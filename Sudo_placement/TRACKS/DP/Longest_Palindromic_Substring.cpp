// Initial template for C++

#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string);

// Your code will be pasted here

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << longestPalindrome(str) << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// A : given string
// return the required string
string longestPalindrome(string s) {
    // code here
    int n=s.length();
    int maxi=0,loc=-1,i,j,k;
    int dp[n][n];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	 { 
	   dp[i][i]=1;
	   if(maxi<(i-i+1))
	   {
	    maxi=1;
	    loc=i;
	   }
	 }
	for(k=2;k<=n;k++)
	 {
	   for(i=0;i<=n-k;i++)
	    {
	      j=i+k-1;      
	      if(k==2)
	        {
	         if(s[i]==s[j])
	           {
	             dp[i][j]=1;
	             if(maxi<(j-i+1))
	             {
	              loc=i;
	              maxi=(j-i+1);
	             }
	           }
	         }
	      else
	       {
	         if(s[i]==s[j] && dp[i+1][j-1]==1)
	           {
	               //cout<<i<<j<<endl;   
	             dp[i][j]=1;
	             if(maxi<(j-i+1))
	             {
	              loc=i;
	              maxi=(j-i+1);
	             }
	           }
	       }
	   }
	}
  return s.substr(loc,maxi);	
}