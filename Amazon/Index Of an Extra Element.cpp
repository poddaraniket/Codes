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
	    int a[n],b[n-1];
	    for(int i=0;i<n;i++)
	     cin>>a[i];
	    for(int i=0;i<n-1;i++)
	     cin>>b[i]; 
	    int l=0,r=n-1;
	    while(l<r)
	     {
	         //cout<<"*"<<endl;
	         int mid=(l+r)/2;
	        // cout<<mid<<endl;
	         if(a[mid]<b[mid])
	           r=mid-1;
	         else
	           l=mid+1;
	     }
	    cout<<l<<endl; 
	}
	return 0;
}
