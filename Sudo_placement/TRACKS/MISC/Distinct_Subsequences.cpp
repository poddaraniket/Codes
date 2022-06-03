using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    vector<long long int> last(256,-1);
	    string str; 
	    cin>>str;
	    long long int dp[str.length()+1];
	    dp[0]=1;
	    for(int i=1;i<=str.length();i++)
	     {
	         dp[i]=(2*dp[i-1])%1000000007;
	         if(last[str[i-1]]!=-1)
	          dp[i]=dp[i]-dp[last[str[i-1]]];
	         last[str[i-1]]=i-1; 
	         if(dp[i]<0)
	          dp[i]+=1000000007;
	     }
	    cout<<dp[str.length()]<<endl; 
	}
	return 0;
}