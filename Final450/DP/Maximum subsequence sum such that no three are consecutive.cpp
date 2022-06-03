#include <bits/stdc++.h>
using namespace std;


// Process rest of the elements
    // We have three cases
    // 1) Exclude arr[i], i.e., sum[i] = sum[i-1]
    // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
    // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]

int maxSumWO3Consec(int arr[], int n)
{
    int sum[n];
    if(n>=1){
     sum[0]=arr[0];    
     //return arr[0];
    }
    if(n>=2){
     sum[1]=sum[0]+arr[1];    
     //return arr[0]+arr[1];
    }
    if(n>2){
        sum[2]=max(arr[0]+arr[2],max(sum[1],arr[1]+arr[2]));    
    } 
    for(int i=3;i<n;i++)
     {
        sum[i]=max(sum[i-2]+arr[i],max(sum[i-1],sum[i-3]+arr[i-1]+arr[i])); 
     }
    return sum[n-1]; 
}

int main()
{
    int arr[] = { 100, 1000, 100, 1000, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumWO3Consec(arr, n);
    return 0;
}
