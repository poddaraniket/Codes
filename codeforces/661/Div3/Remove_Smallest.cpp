#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,count;
	    cin>>n;
	    count=n;
	    int a[n];
	    for(int i=0;i<n;i++)
	     cin>>a[i];
	    sort(a,a+n);
	    for(int i=0;i<n-1;i++)
	     {
	       if(abs(a[i]-a[i+1])<=1)
	        count--;
	     }
	    if(count==1)
	     cout<<"YES"<<endl;
	    else
	     cout<<"NO"<<endl;
	}
	return 0;
}
