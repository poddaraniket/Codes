#include<bits/stdc++.h>

using namespace std;

long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    //Your code here
    long long int count=0,sum=0;
    unordered_map<int,long long int> mp;
    //int a[n];
    for(int i=0;i<n;i++)
    {
       if(arr[i]==0)
         arr[i]=-1;
       sum+=arr[i];
       if(sum==0)
        count++;
       if(mp[sum]!=0)    
        count+=mp[sum];
       mp[sum]++;
    }
    return count;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    cout<<countSubarrWithEqualZeroAndOne(arr,n)<<endl;   
  }  
}