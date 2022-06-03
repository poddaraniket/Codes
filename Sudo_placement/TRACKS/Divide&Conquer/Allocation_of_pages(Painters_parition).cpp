#include<bits/stdc++.h>

using namespace std;

#define ll long long int 

bool isValid(int arr[],int n,int k,ll mid)
{
    int i;
    int student=1,currentpage=0;
    for(i=0;i<n;i++)
     {
        if(currentpage+arr[i]<=mid)
         {
            currentpage+=arr[i]; 
         }
        else
         {
            ++student;
            currentpage=arr[i];
            if(student>k)
             return false;
         }
     }
    return true; 
}

ll Partition(int arr[],int n,ll first,ll last,int k)
{
  ll final_ans=0;    
  while(first<=last)
   {
       ll mid=(first+last)/2;
       if(isValid(arr,n,k,mid))
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
     int n,i,j,s=0,maxi=0;    
     cin>>n;
     int a[n];
     for(i=0;i<n;i++)
      {
       cin>>a[i];
       s+=a[i];
       maxi=max(maxi,a[i]);
      }
     int m;
     cin>>m;
     cout<<Partition(a,n,maxi,s,m)<<endl;
    }
}