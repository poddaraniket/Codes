#include <boost/multiprecision/cpp_int.hpp>
#include<bits/stdc++.h>
using namespace boost::multiprecision; 
using namespace std;


void binomial(int n,int r)
{
    int i;
    int1024_t res=1;
    if(r>n-r)
     r=n-r;
    for(i=0;i<r;i++)
     {
         res*=(int1024_t)(n-i);
         res/=(int1024_t)(i+1);
     }
    cout<<res/(r+1)<<endl; 
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
      int n;
      cin>>n;
      binomial(2*n,n);
     }
}


/* Using DP

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Functiuon to return number of trees

// Return the total number of BSTs possible with keys [1....N] inclusive.

long numTreesUtil(int N)
{
    long dp[N+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=N;i++)
     {
         for(int j=1;j<=i;j++) 
          {
              dp[i]=(dp[i]+((dp[j-1]*dp[i-j])%1000000007))%1000000007;
          }
     }
    return dp[N]; 
}

int numTrees(int N) {
    // Your code here
    return (int)numTreesUtil(N);
}

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        
        //calling function numTrees()
        cout<<numTrees(n)<<"\n";
    }
}     // } Driver Code Ends
*/