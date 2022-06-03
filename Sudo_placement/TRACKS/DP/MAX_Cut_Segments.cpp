#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        int x,y,z;
        cin>>x>>y>>z;
        
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends


//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    int i,j;
    int dp[n+1]={0};
    int a[3]={x,y,z};
    for(i=0;i<3;i++)
     {
         for(j=1;j<=n;j++)
          {
            if(a[i]==j)
             {
                dp[j]=max(1,dp[j]); 
             }
            else if(a[i]<j)
             {
                if(dp[j-a[i]]!=0)
                 {
                    dp[j]=max(dp[j-a[i]]+1,dp[j]); 
                 }
             }
          }
     }
    return dp[n]; 
}