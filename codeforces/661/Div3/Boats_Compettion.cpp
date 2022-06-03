#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    set<int> s;
	    map<int,int> mp,rt;
	    for(int i=0;i<n;i++)
	     {
	         cin>>a[i];
	         s.insert(a[i]);
	         mp[a[i]]++;
	     }
	    int len=s.size(); 
	    int cmp[len],p=0; 
	    for(auto it=s.begin();it!=s.end();it++)
	     {
	         cmp[p++]=*it;
	     }
	    for(int i=0;i<len;i++)
	     {
	         int temp=cmp[i]*2;
	         rt[temp]+=mp[cmp[i]]/2;
	         for(int j=i+1;j<len;j++)
	          {
	              temp=cmp[i]+cmp[j];
	              rt[temp]+=min(mp[cmp[i]],mp[cmp[j]]);
	          }
	     }
	    int maxi=-1; 
	    for(auto it=rt.begin();it!=rt.end();it++)
	     maxi=max(maxi,it->second);
	    cout<<maxi<<endl; 
	}
	return 0;
}