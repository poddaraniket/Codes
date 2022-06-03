#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[],int n)
{
    int countNeg=0,minNeg=-1,countZero=0,pro=1;
    for(int i=0;i<n;i++)
     {
        if(a[i]==0){
         countZero++;
         continue;
        }
        
        if(a[i]<0){
         countNeg++;
         minNeg=min(minNeg,abs(a[i]));
        }
        pro*=a[i];
     }
    if(countZero==n)
     return 0;
    if(countNeg%2!=0) {
       if(countZero>0 && countNeg==1 && countNeg+countZero==n)
        {
            return 0; 
        }
       return pro/minNeg;    
    }
    
    return pro;
         
    
}

int main()
{
    int a[] = {  -1, -1, -2, 4, 3  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;
}