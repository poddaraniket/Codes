#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[],int n)
{
    int curr_sum=0,curr_val=0,val,res=0;
    for(int i=0;i<n;i++)
    {
     curr_sum+=arr[i];
     curr_val+=arr[i]*i;
    }
    for(int i=1;i<n;i++)
     {
        val=(curr_val-(curr_sum-arr[i-1]))+(arr[i-1]*(n-1));
        curr_val=val;
        res=max(res,val);
     }
    return res; 
}

int main() {
	// your code goes here
	int arr[] = {8, 3, 1, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << maxSum(arr, n) << endl; 
	return 0;
}
