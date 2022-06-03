#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	    int n,i,max=0;
	    vector<int> v;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	     {
	         cin>>a[i];
	     }
	    for(i=n-1;i>=0;i--)
	     {
	         if(a[i]>=max)
	          {
	              max=a[i];
	              v.push_back(a[i]);
	          }
	     }
	    for(i=v.size()-1;i>=0;i--)
	     cout<<v[i]<<" ";
	    cout<<endl; 
	 }
	return 0;
}
