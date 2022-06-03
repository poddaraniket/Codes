#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.second!=b.second)
     return a.second>b.second;
    else if(a.second==b.second)
     return (a.first<b.first);
}

int main()
{
  int t;
  cin>>t;
  while(t--)
   {
     int n,i,num;
     int a[61]={0};
     cin>>n;
     for(i=0;i<n;i++)
      {
        cin>>num;
        a[num]++;
      }
     vector<pair<int,int>> v;
     for(i=1;i<=60;i++)
      {
        if(a[i]!=0)
         v.push_back(make_pair(i,a[i]));
      }
     sort(v.begin(),v.end(),comp); 
     for(i=0;i<v.size();i++)
      {
        int j=v[i].second;
        while(j--)
         cout<<v[i].first<<" ";
      }
     cout<<endl; 
   }
	return 0;
}