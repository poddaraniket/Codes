#include <bits/stdc++.h>
using namespace std;

int removals(int a[],int n,int k){
    sort(a,a+n);
    int minRemoval=n;
    for(int i=0;i<n-1;i++){
        int val=a[i];
        int low=i+1;
        int high=n-1;
        int ans=low;
        while(low<=high){
            int mid=(low+high)/2;
             //cout<<"mid "<<i<<"->"<<mid<<endl;
            if(a[mid]-val>k){
             high=mid-1;
            // cout<<"*"<<high<<endl;
            }
            else{
                ans=mid;
                low=mid+1;
            } 
        }
        if(a[ans]-val<k){
            minRemoval=min(minRemoval,n-(ans+1)+i);
           // cout<<minRemoval<<endl;
        }
    }
    return minRemoval;
    
}

int main()
{
    int a[] = {1, 5, 6, 2, 8};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;
    cout << removals(a, n, k);
    return 0;
}
