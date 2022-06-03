
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    set<string> st;
	    int n,count=0,len;
	    string s;
	    cin>>s;
	    n=s.length();
	    int dp[n][n];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<n;i++)
	    {
	     dp[i][i]=1;
	     len=(i-i+1);
	     st.insert(s.substr(i,len));
	    }
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
	                len=(j-i+1);
	                st.insert(s.substr(i,len));
	               }
	          }
	         else
	          {
	              if(s[i]==s[j] && dp[i+1][j-1]==1)
	              {
	               //cout<<i<<j<<endl;   
	               dp[i][j]=1;
	               len=(j-i+1);
	               st.insert(s.substr(i,len));
	              }
	          }
	       }
	    }
	   cout<<st.size()<<endl; 
	}
	return 0;
}