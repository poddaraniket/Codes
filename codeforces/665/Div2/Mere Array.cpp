#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,flag=0,srt=0,mini=1000000000;
	    cin>>n;
	    set<int> s;
	    int a[n],b[n];
	    for(int i=0;i<n;i++)
	    {
	     cin>>a[i];
	     b[i]=a[i];
	     mini=min(mini,b[i]);
	    }
	    sort(b,b+n);
	    for(int i=0;i<n;i++)
	     {
	       if(b[i]!=a[i])
	        {
	           srt=1;
	           s.insert(a[i]);
	           s.insert(b[i]);
	           if(a[i]%mini!=0)
	            flag=1;
	        }
	     }
	    if(srt==0 || flag==0)
	     cout<<"YES"<<endl;
	    else
	     cout<<"NO"<<endl;
	}
	return 0;
}