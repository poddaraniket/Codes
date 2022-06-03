#include <bits/stdc++.h>
using namespace std;

int forPos(int A[],int n,int k,int ans)
{
    int l=0,r=n-1;
    k=k/2;
    while(k!=0)
     {
        if(l+1!=r-1)
         {
            if(A[l]*A[l+1]>A[r]*A[r-1])
             {
                ans*=A[l]*A[l+1];
                l+=2;
             }
            else
             {
                ans*=A[r]*A[r-1];
                r-=2; 
             }
         }
        k--; 
     }
    return ans; 
}

int maxProductSubarrayOfSizeK(int A[],int n,int k)
{
    sort(A,A+n);
    int maxNum=A[n-1];
    int ans=1;
    if(k%2!=0)
     {
        if(maxNum==0)
         return 0;
        if(maxNum<0)
         {
            for(int i=n-1;i>=n-k;i--)
             ans*=A[i];
             
         }
        else
         {
            ans=forPos(A,n-1,k-1,maxNum);
         }
     }
    else
     ans=forPos(A,n,k,1);
    return ans; 
}

int main()
{
    int A[] = { 1, 2, -1, -3, -6, 4 };
    int n = sizeof(A) / sizeof(A[0]);
    int k = 4;
    cout << maxProductSubarrayOfSizeK(A, n, k);
 
    return 0;
}