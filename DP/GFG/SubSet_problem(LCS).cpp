#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     long long int n,i,s=0,j,temp;
	     cin>>n;
	     long long int a[n];
	     for(i=0;i<n;i++)
	      {
	         cin>>a[i];
	         s+=a[i];
	      }
	     //a[0]=-1; 
	     //int dp[n+1][s+1]; 
	     if(s%2!=0)
	      cout<<"NO"<<endl;
	     else
	       {
	           temp=s/2;
	           bool dp[n+1][temp+1];
	           for(i=0;i<=temp;i++)
	             dp[0][i]=false;
	           for(i=0;i<=n;i++)
	            dp[i][0]=true;
	          // sort(a,a+n);
	           for(i=1;i<=n;i++)
	            {
	              for(j=1;j<=temp;j++)
	                {
	                   if(a[i-1]>j)
	                    dp[i][j]=dp[i-1][j];
	                   else
	                    dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
	                }
	            }
	       //  for(i=0;i<=n;i++)
	       //   {
	       //       for(j=0;j<=temp;j++)
	       //        cout<<dp[i][j]<<" ";
	       //       cout<<endl;    
	       //   }
	         if(dp[n][temp])
	          cout<<"YES"<<endl;
	         else
	          cout<<"NO"<<endl;
	       }
	 }
	return 0;
}
