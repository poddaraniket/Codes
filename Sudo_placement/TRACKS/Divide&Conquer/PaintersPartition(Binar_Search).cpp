#include<bits/stdc++.h>

using namespace std;
#define ll long long int 


bool isValidConfig(int arr[],int n,int k,ll mid)
{
    int painter=1,s=0;
    for(int i=0;i<n;i++)
     {
        if(arr[i]+s<=mid)
         s+=arr[i];
        else
         {
            s=arr[i];
            ++painter;
            if(painter>k)
             return false;
         }
     }
    return true; 
}

ll Partition(int arr[],int n,int k,ll last,ll first)
{
    ll final_ans=last;
    //ll first=arr[0];
    //ll last=sum;
    while(first<=last)
    {
        ll mid=(first+last)/2;
        if(isValidConfig(arr,n,k,mid))
         {
            final_ans=mid;
            last=mid-1;
         }
        else
         first=mid+1;
    }
  return final_ans;    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n,s=0,maxi=0;
        cin>>k>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
         cin>>a[i];
         s+=a[i];
         maxi=max(maxi,a[i]);
        }
        cout<<Partition(a,n,k,s,maxi)<<endl; 
    }
}