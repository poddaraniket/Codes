#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
   {
     int mp[100001]={0};  
     int n,k,i;
     cin>>n>>k;
     set<int> s;
     int a[n];
     //map<int,int> mp;
     for(i=0;i<n;i++)
      cin>>a[i];
     for(i=0;i<k;i++)
      {
        mp[a[i]]++;
        s.insert(a[i]);
      }
     int c=s.size(); 
     cout<<s.size()<<" ";
     for(i=1;i<=n-k;i++)
      {
        if(mp[a[i-1]]==1)
         {
            c--;
            // mp.erase(a[i-1]);
         }
        mp[a[i-1]]--;
        if(mp[a[i+k-1]]==0)
         {
           c++;
         }
        mp[a[i+k-1]]++;
        cout<<c<<" "; 
      }
    cout<<endl;  
   }
	return 0;
}