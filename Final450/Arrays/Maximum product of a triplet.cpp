#include <bits/stdc++.h>
using namespace std;

int maxProduct(int arr[],int n)
{
    if(n<3)
     return -1;
    sort(arr,arr+n);
    if(arr[n-1]<0 || arr[0]>0)
     return arr[n-1]*arr[n-2]*arr[n-3];
    // frst Min * sec min * largest -> if we have negative numbers
    // last three largest numbers -> all positive [intention]
    return max(arr[0]*arr[1]*arr[n-1], arr[n-1]*arr[n-2]*arr[n-3]);
}

int main()
{
    int arr[] = { 10, 3, 5, 6, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int max = maxProduct(arr, n);
 
    if (max == -1)
        cout << "No Triplet Exists";
    else
        cout << "Maximum product is " << max;
 
    return 0;
}