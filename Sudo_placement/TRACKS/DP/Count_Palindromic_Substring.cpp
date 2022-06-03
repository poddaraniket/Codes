
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,count=0;
	    cin>>n;
	    string s;
	    cin>>s;
	    int dp[n][n];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<n;i++)
	     dp[i][i]=1;
	    for(int k=2;k<=n;k++)
	    {
	      for(int i=0;i<=n-k;i++)
	       {
	         int j=i+k-1;      
	         if(k==2)
	          {
	              if(s[i]==s[j])
	               {
	                dp[i][j]=1;
	                //cout<<i<<j<<endl;
	                count++;
	               }
	          }
	         else
	          {
	              if(s[i]==s[j] && dp[i+1][j-1]==1)
	              {
	               //cout<<i<<j<<endl;   
	               dp[i][j]=1;
	               count++;
	              }
	          }
	       }
	    }
	   cout<<count<<endl; 
	}
	return 0;
}