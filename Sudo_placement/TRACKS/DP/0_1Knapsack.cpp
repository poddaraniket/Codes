#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   int cap[n+1][W+1];
   int i,j;
   for(i=0;i<=n;i++)
    {
        cap[i][0]=0;
    }
   for(i=0;i<=W;i++)
    {
        cap[0][i]=0;
    }
   for(i=1;i<=n;i++)
    {
        for(j=1;j<=W;j++)
         {
            if(j<wt[i-1])
             {
                cap[i][j]=cap[i-1][j]; 
             }
            else
             cap[i][j]=max(val[i-1]+cap[i-1][j-wt[i-1]],cap[i-1][j]);
         }
    }
   return cap[n][W];    
}





// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends