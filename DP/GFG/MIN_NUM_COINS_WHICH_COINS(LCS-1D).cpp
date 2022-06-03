#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int a[]={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int t;
	cin>>t;
	while(t--)
	 {
        int n,i,j,p;
        cin>>n;
        int dp[n+1],lis[n+1];
        for(i=0;i<=n;i++)
         dp[i]=100000000;
        dp[0]=0;
        lis[0]=0;
        for(i=0;i<10;i++)
         {
            for(j=1;j<=n;j++)
             {
                 if(a[i]<=j)
                  {
                      if(dp[j-a[i]]+1<dp[j])
                       {
                          dp[j]=dp[j-a[i]]+1;
                          lis[j]=a[i];
                       }
                  }
             }
         }
        p=n;
        while(p)
         {
             cout<<lis[p]<<" ";
             p-=lis[p];
         }
        cout<<endl; 
	 }
	return 0;
}
