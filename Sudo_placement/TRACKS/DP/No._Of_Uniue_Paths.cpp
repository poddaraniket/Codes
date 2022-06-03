//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int NumberOfPath( int, int);

// Position this line where user code will be pasted

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout << NumberOfPath(a,b) << endl;
    }
}

// } Driver Code Ends


//User function template in C++

int NumberOfPath(int a, int b) {
    //code here
    int dp[a][b];
    int i,j;
    for(i=0;i<=a;i++)
     {
        dp[i][0]=1;
     }
    for(i=0;i<=b;i++)
     {
        dp[0][i]=1; 
     }
    for(i=1;i<a;i++)
     {
        for(j=1;j<b;j++)
         {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]; 
         }
     }
    return dp[a-1][b-1]; 
}
