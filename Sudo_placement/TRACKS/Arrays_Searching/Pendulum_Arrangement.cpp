#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	    int n,temp,p=1,i;
	    cin>>n;
	    int a[n],b[n];
	    for(i=0;i<n;i++)
	     cin>>a[i];
	    sort(a,a+n); 
	    if(n>2)
	    {
	      if(n%2==0)
	       {
	         b[(n-1)/2]=a[0];
	         temp=(n-1)/2;
	       }
	      else
	        {
	          b[n/2]=a[0];
	          temp=n/2;
	        }
	       for(i=1;i<n;i+=2)
	        {
	          b[temp+p]=a[i];
	          p++;
	        }
	        p=1;
	       for(i=2;i<n;i+=2)
	        {
	            b[temp-p]=a[i];
	            p++;
	        }
	       for(i=0;i<n;i++)
	        cout<<b[i]<<" ";
	       cout<<endl; 
	    }
	   else
	   {
	    for(i=0;i<n;i++)
	     cout<<a[i]<<" ";
	    cout<<endl; 
	   }
	 }
	return 0;
}
