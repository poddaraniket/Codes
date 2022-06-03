//Find maximum sum of triplets in an array such than i < j < k and a[i] < a[j] < a[k]


// C++ program to find maximum triplet sum
#include <bits/stdc++.h>
using namespace std;
 
// Function to calculate maximum triplet sum

int binarySearch(int left[],int l,int r,int val)
{
    int best=0;
    while(l<=r)
     {
        int m=l+(r-l)/2;
        if(left[m]<=val)
         {
            l=m+1;
            best=m;
         }
        else
         {
             r=m-1;
         }
     }
    return left[best]; 
}


int maxTripletSum(int arr[], int n)
{
    
    int left[n];
    int right[n];
    left[0]=arr[0];
    right[n-1]=arr[n-1];
    for(int i=1;i<n;i++)
     {
         left[i]=max(left[i-1],arr[i]);
     }
    for(int i=n-2;i>=0;i--)
     {
         right[i]=max(right[i+1],arr[i]);
     }
    int ans=0; 
    for(int i=1;i<n-1;i++)
     {
        int b=arr[i];
        int c=right[i+1];
        int a=binarySearch(left,0,i-1,b);
        ans=max(ans,a+b+c);
     }
    return ans;
}
 
// Driver code
int main()
{
    int arr[] = { 2, 5, 3, 1, 4, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxTripletSum(arr, n);
    return 0;
}