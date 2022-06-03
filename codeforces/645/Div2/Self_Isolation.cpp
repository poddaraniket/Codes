#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     vector<pair<long long int,long long int>> v;
	     map<long long int,long long int> mp;
	     long long int n,count=0,i;
	     cin>>n;
	     long long int a[n];
	     for(i=0;i<n;i++)
	      {
	       cin>>a[i];
	       mp[a[i]]++;
	      }
	     long long int prev=0; 
	     for(auto it=mp.begin();it!=mp.end();it++)
	      {
	          v.push_back(make_pair(it->first,it->second+prev));
	          prev+=it->second;
	      }
	     for(i=0;i<v.size();i++)
	      {
	          if(v[i].first<=v[i].second)
	           count=1+v[i].second;
	      }
	     if(count==0)
	      cout<<"1"<<endl;
	     else
	      cout<<count<<endl;
	 }
	return 0;
}