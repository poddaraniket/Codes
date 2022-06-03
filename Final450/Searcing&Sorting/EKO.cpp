#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> v,long long int mid,int woods,int n)
{
    int length=0;
    for(int i=0;i<n;i++)
     {
        if(mid<v[i])
         {
            length+=(v[i]-mid);
            if(length>=woods)
             return true;
         }
     }
    return false; 
}

int binarySearch(vector<int> v,long long int start,long long int end,int woods,int n){
   long long int best=0;
   while(start<=end){
      long long int mid=(start+end)/2;
      if(isValid(v,mid,woods,n))
       {
           best=mid;
           start=mid+1;
       }
      else
       {
           end=mid-1;
       }
   }
   return best;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    long long int start=0,end=0;
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
      end=max(end,(long long int)v[i]);
    }
    cout<< binarySearch(v,start,end,m,n)<<endl;
}