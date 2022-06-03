#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
       long long int n,ans;
       cin>>n;
       int dp[4];
       dp[0]=0;
       dp[1]=3;
       dp[2]=8;
       dp[3]=19;
       if(n>3)
       {
        int t=((n-1)*(n-2))/2;
        ans=(n*t)+(n*(n-1))+((n*(n-1))/2)+(2*n)+1;  //  1+(n*2)+(n*((n*n)-1)/2)
        cout<<ans<<endl;
       }
      else
       {
          cout<<dp[n]<<endl; 
       }
	 }
	return 0;
}
