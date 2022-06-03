#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v,int low,int high,int cows,int n){
   int best=0;
   while(low<=high){
       int count=1,left=v[0];
       int mid=(low+high+1)/2;
       for(int i=1;i<n && count<cows ;i++)
        {
           if(v[i]-left>=mid)
            {
                left=v[i];
                count++;
            }
        }
       if(count>=cows){
        low=mid+1;
        best=mid;   
       }
       else
        high=mid-1;
   }
   return best;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,c;
    cin>>n>>c;
    vector<int> v(n);
    for(int i=0;i<n;i++)
      cin>>v[i];
    sort(v.begin(),v.end());  
    cout<< binarySearch(v,0,v[n-1],c,n)<<endl;
    }
}