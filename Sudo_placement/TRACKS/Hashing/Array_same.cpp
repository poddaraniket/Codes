#include<bits/stdc++.h>

using namespace std;

bool check(vector<ll> arr, vector<ll> brr, int n) {
    //code here
    map<long long int,int> m,p;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
        p[brr[i]]++;
    }
    map<long long int, int>::iterator itr,itr1;
    if(m.size()==p.size())
     {
        itr=m.begin();
        itr1=p.begin();
        while(itr!=m.end() && itr1!=p.end())
        {
            if(itr->first==itr1->first)
             {
                 if(itr->second!=itr1->second)
                  return false;
             }
            else
             return false;
            itr++;
            itr1++;
        }
     }
    else
     return false;
    return true; 
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    for(int i=0;i<n;i++)
     cin>>arr[i]; 
    cout<<countSubarrWithEqualZeroAndOne(arr,brr,n)<<endl;   
  }  
}