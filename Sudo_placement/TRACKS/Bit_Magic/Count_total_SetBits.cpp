
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	 {
	     int dp[1001]={0};
	     long long int n,s=0,i,temp;
	     cin>>n;
	     for(i=1;i<=n;i++)
	     {
	         if(i%2!=0)
	          {
	              dp[i]=dp[i-1]+1;
	              s+=dp[i];
	          }
	         else
	           {
	               if(ceil(log2(i)) == floor(log2(i)))
	                {
	                    dp[i]=1;
	                    s+=dp[i];
	                    temp=i;
	                }
	               else
	                {
	                   dp[i]=dp[i-temp]+dp[temp];
	                   s+=dp[i];
	                }
	           }
	     }
	    cout<<s<<endl; 
	 }
}