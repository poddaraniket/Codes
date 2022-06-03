// Find minimum possible size of array with given rules for removing elements

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int dp[MAX][MAX];

int minSizeAr(int arr[],int low,int high,int k)
{
    if(dp[low][high]!=-1)
     return dp[low][high];
    
    if(high-low+1<3)
     return high-low+1;
    
    // if low is not removable [1 element is fixed to stay till end]
    int res=1+minSizeAr(arr,low+1,high,k); // size of array that stays to be returned
    
    // if low is removable
    
    // ways to take low and get it removed
    for(int i=low+1;i<=high-1;i++)
     {
         for(int j=i+1;j<=high;j++)
          {
            // condidtion accepted and elements in between the (low & i) and (i & j) can be removed 
            if((arr[i]==arr[low]+k) && (arr[j]==arr[low]+2*k) && (minSizeAr(arr,low+1,i-1,k)==0) && (minSizeAr(arr,i+1,j-1,k)==0)) 
             {
                // it can be removed so size that remais after from j+1 
                res= minSizeAr (arr,j+1,high,k);
             }
          }
     }
    return dp[low][high]=res; 
}

int minSize(int arr[],int n,int k)
{
    memset(dp,-1,sizeof(dp));
    return minSizeAr(arr,0,n-1,k);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    cout << minSize(arr, n, k) << endl;
    return 0;
}