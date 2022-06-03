 
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s,d,k;
        cin>>n;
        int graph[n][n];
        //vector<int> adj[n];
        for(int i=0;i<n;i++)
         {
            for(int j=0;j<n;j++)
            {
             cin>>graph[i][j];
            }
         }
        cin>>s>>d>>k; 
        int dp[n][k+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
         {
            if(i==s)
             dp[i][0]=1;
            else
             dp[i][0]=0;
         }
        for(int j=0;j<k;j++)
         {
            for(int i=0;i<n;i++)
             {
                if(dp[i][j]!=0)
                 {
                    for(int p=0;p<n;p++)
                     {
                        if(graph[i][p]==1)
                         dp[p][j+1]+=dp[i][j];
                     }
                 }
             }
         }
        cout<<dp[d][k]<<endl; 
    }
}