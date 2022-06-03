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
	    vector<long long int> vec(n);
	    for(int i=0;i<n;i++)
	     {
	       cin>>vec[i];
	     }
	    sort(vec.begin(),vec.end());
	    long long int maxi=-1e18;
	    for(int i=0;i<5;i++)
	     {
	         int a,b,c,d,e;
	         a=(n-1+i)%n;
	         b=(n-2+i)%n;
	         c=(n-3+i)%n;
	         d=(n-4+i)%n;
	         e=(n-5+i)%n;
	         long long int val=vec[a]*vec[b]*vec[c]*vec[d]*vec[e];
	         maxi=max(val,maxi);
	     }
	    cout<<maxi<<endl; 
	}
	return 0;