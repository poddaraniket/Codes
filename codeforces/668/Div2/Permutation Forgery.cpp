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
	     cin>>a[i];
	    int sum[n-1];
	    for(int i=0;i<n-1;i++) 
	    {
	      sum[i]=a[i]+a[i+1];  
	    }
	    if(n%2==0)
	     {
	         for(int i=n-1;i>=0;i--)
	          cout<<a[i]<<" ";
	     }
	    else
	     {
	        int start=0,loc; 
	        for(int i=0;i<n-1;i++)
	         {
	             if(sum[i]-a[n-1]>0)
	              {
	                  if(sum[i]-a[n-1]==a[i])
	                   {
	                     loc=i;
	                     break;
	                   }
	                  else if(sum[i]-a[n-1]==a[0])
	                   {
	                     loc=i;
	                     start=1;
	                     break;
	                  }
	              }
	         }
	        for(int i=loc+1;i<n;i++)
	           cout<<a[i]<<" "; 
	        if(start==1)
	         {
	             for(int i=0;i<=loc;i++)
	              cout<<a[i]<<" ";
	         }
	        else
	         {
	             for(int i=loc;i>=0;i--)
	              cout<<a[i]<<" ";
	         }
	     }
	    cout<<endl; 
	}
	return 0;
}