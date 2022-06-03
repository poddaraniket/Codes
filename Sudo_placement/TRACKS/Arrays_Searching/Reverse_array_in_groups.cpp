#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	    int n,i,p=0,k,j;
	    cin>>n>>k;
	    int a[n],b[n];
	    for(i=0;i<n;i++)
	     {
	        cin>>a[i]; 
	     }
	    for(i=0;i<n;i+=k)
	     {
	       j=i+k-1;
	       if(j<n)
	       {
	        for(;j>=i;j--)
	        {
	            b[p++]=a[j];
	        }
	       }
	       else
	        {
	        for(j=n-1;j>=i;j--)
	         b[p++]=a[j];
	        }
	     }
	     
	     for(i=0;i<n;i++)
	      cout<<b[i]<<" ";
	     cout<<endl; 
	 }
	return 0;
}
