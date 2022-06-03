#include <bits/stdc++.h>

using namespace std;

int main() {
  Hashmap<int,int> mp;
  int n,i,j;
  cin>>n;
  //string s_diff;
  int a[n];
  for(i=0;i<n;i++)
   cin>>a[i];
  for(i=1;i<n;i++)
   {
     for(j=0;j<i;j++)
      {
        int diff=a[j]-a[i];
        if(mp[j].containskey(diff))
         {
           if(mp[i].containskey(diff)&& mp[i].get(diff)<mp[j].get(diff))
            mp[i].put(diff,mp.get(diff)+1);
         }
        else
          mp[i].put(diff,1);
      }
   }
  int maxi=0;
  for(i=0;i<n;i++)
  {
    for(Integer key:mp[i].keySet())
     {
        maxi=max(maxi,mp[i].get(key))
     }
  }
  return maxi;
}