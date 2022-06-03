#include <bits/stdc++.h>
using namespace std;

bool sortbydesc(pair<string,int> a, pair<string,int> b)
{
    if(a.second!=b.second)
     return a.second>b.second;
    else
     return a.first<b.first; 
}

int main()
{
  int t;
  cin>>t;
  while(t--)
   {
     int n,i;
     cin>>n;
     string a[n];
     map<string,int> mp;
     vector<pair<string,int>> v;
     for(i=0;i<n;i++)
      {
        cin>>a[i];
        mp[a[i]]++;
      }
     for(auto it=mp.begin();it!=mp.end();it++)
      {
        v.push_back(make_pair(it->first,it->second));  
      }
     sort(v.begin(),v.end(),sortbydesc);
     cout<<v[0].first<<" "<<v[0].second<<endl;
   }
	return 0;
}