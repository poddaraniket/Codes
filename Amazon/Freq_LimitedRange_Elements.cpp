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
	    for(int i=0;i<n;i++)
	     {
	      cin>>a[i];
	      a[i]*=(n+1);
	     }
	    for(int i=0;i<n;i++)
	     {
	         int temp=a[i]/(n+1);
	         a[temp-1]++;
	     }
	   // for(int i=0;i<n;i++)
	   //  cout<<a[i]<<" "; 
	    for(int i=0;i<n;i++)
	     cout<<a[i]%(n+1)<<" ";
	    cout<<endl; 
	}
	return 0;
}
