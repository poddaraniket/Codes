
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,amt,i,j,max=1000000;
	    cin>>n>>amt;
	    int coins[n],dp[amt+1];
	    memset(dp,max,sizeof(dp));
	    dp[0]=0;
	    for(i=0;i<n;i++)
	     cin>>coins[i];
	    for(i=0;i<n;i++)
	     {
	         for(j=0;j<=amt;j++)
	          {
	              //cout<<"*";
	              if(coins[i]<=j)
	               {
	                   //cout<<"*";
	                   if(dp[j]==0) 
	                     dp[j]=dp[j-coins[i]]+1;
	                   else  
	                     dp[j]=min(dp[j],dp[j-coins[i]]+1);
	               }
	          }
	     }
	   // for(i=0;i<=amt;i++)
	   //  cout<<dp[i]<<" ";
	   // cout<<endl; 
	    if(dp[amt]>max)
	     cout<<"-1"<<endl;
	    else
	     cout<<dp[amt]<<endl;
	}
	return 0;
}