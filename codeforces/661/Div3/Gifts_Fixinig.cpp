#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,minia=10000000000,minib=10000000000,count=0;
	    cin>>n;
	    //count=n;
	    long long int a[n],b[n];
	    for(int i=0;i<n;i++)
	     {
	      cin>>a[i];
	      minia=min(minia,a[i]);
	     }
	    for(int i=0;i<n;i++)
	     {
	      cin>>b[i];
	      minib=min(minib,b[i]);
	     } 
	    //sort(a,a+n);
	    for(int i=0;i<n;i++)
	     {
	        int diffa=a[i]-minia;
	        int diffb=b[i]-minib;
	        count+=max(diffa,diffb);
	     }
	    cout<<count<<endl; 
	}
	return 0;
}