// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	// your code goes here
// 	long long int n,i,j;
// 	int a[5]={1,5,10,20,100};
// 	cin>>n;
// 	long long int dp[n+1]={0};
// 	dp[1]=1;
// 	dp[5]=1;
// 	dp[10]=1;
// 	dp[20]=1;
// 	dp[100]=1;
// 	for(i=0;i<5;i++)
// 	 {
// 	     for(j=1;j<=n;j++)
// 	      {
// 	          if(a[i]<j)
// 	          {
// 	            if(dp[j]!=0 && dp[j-a[i]]!=0)
// 	              dp[j]=min(dp[j],dp[j-a[i]]+1);
// 	            else if(dp[j]==0)
// 	              dp[j]=dp[j-a[i]]+1;
// 	          }
// 	      }
// 	 }
// 	cout<<dp[n]<<endl; 
// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x,y,i,sum=0;
	    cin>>n>>x>>y;
	    int dp[n]={0},a[n],b[n];
	    vector<pair<int,pair<int,int>>> v;
	    for(i=0;i<n;i++)
	      cin>>a[i];
	    for(i=0;i<n;i++)
	      cin>>b[i];
	    for(i=0;i<n;i++)
	      v.push_back(make_pair(abs(a[i]-b[i]),make_pair(a[i],b[i])));
	    sort(v.begin(),v.end());
	   //for(i=0;i<n;i++)
	   // {
	   //     cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
	   // }
	   for(i=n-1;i>=0;i--)
	    {
	        if(v[i].second.first>v[i].second.second)
	         {
	             if(x>0)
	              {
	               sum+=v[i].second.first;
	               x--;
	              }
	             else
	               {
	                   sum+=v[i].second.second;
	                   y--;
	               }
	         }
	        else
	         {
	             if(y>0)
	              {
	               sum+=v[i].second.second;
	               y--;
	              }
	             else
	               {
	                   sum+=v[i].second.first;
	                   x--;
	               }
	         } 
	    }
	   cout<<sum<<endl; 
	}
	return 0;
}
