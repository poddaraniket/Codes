#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	    set<int> s;
	    int n,i,mini=1000000,maxi=0;
	    cin>>n;
	    int a[n],b[n],c[n];
	    for(i=0;i<n;i++)
	     {
	         cin>>a[i];
	         c[a[i]-1]=i;
	     }
	    for(i=0;i<n;i++)
	     {
	         cin>>b[i];
	         c[b[i]-1]-=(i);
	         if(c[b[i]-1]<0)
	          c[b[i]-1]=n+c[b[i]-1];
	     }
	    map<int,int> mp; 
	    for(i=0;i<n;i++)
	     {
	        mp[c[i]]++;
	     }
	     for(auto it=mp.begin();it!=mp.end();it++)
	      {
	          maxi=max(it->second,maxi);
	      }
	    //for() 
	    cout<<maxi<<endl;
	return 0;
}