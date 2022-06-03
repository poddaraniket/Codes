#include <bits/stdc++.h>
using namespace std;


int main()
{
  int t;
  cin>>t;
  while(t--)
   {
     map<long long int,long long int> mp;  
     long long int n,i,s=0;
     cin>>n;
     long long int a[n],b[n],lis[n];
     for(i=0;i<n;i++)
      cin>>a[i];
     b[0]=a[0]; 
     mp[b[0]]=1;
     lis[0]=mp[b[0]];
     for(i=1;i<n;i++)
      {
        b[i]=a[i]+b[i-1]; 
        //mp[b[i]]++;
        lis[i]=++mp[b[i]];
      }
    //  for(i=0;i<n;i++)
    //   cout<<lis[i]<<" ";
    //  cout<<endl; 
     for(i=0;i<n;i++)
     {
         if(b[i]==0)
          s+=lis[i];
         else
          s+=(lis[i]-1);
     }
    cout<<s<<endl; 
   }
	return 0;
}