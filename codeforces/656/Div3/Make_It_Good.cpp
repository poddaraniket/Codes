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
	     }
	    //cout<<a[1]<<endl; 
	    int first=0,last=n-1,loc=0,temp=-1;
	    while(first<=last)
	    {
	       if(a[first]<=a[last])
	         {
	            if(a[first]>=temp)
	             {
	                 temp=a[first];
	                 first++;
	             }
	            else
	             {
	                 temp=-1;
	                 loc=first;
	                 last=n-1;
	             }
	         }
	       else
	        {
	            if(a[last]>=temp)
	             {
	                 temp=a[last];
	                 last--;
	             }
	             else
	             {
	                 temp=-1;
	                 first++;
	                 loc=first;
	                 last=n-1;
	             } 
	        }
	    }
	   cout<<loc<<endl; 
	}
	return 0;
}