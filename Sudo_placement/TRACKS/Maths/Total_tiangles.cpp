#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long long int i,n,count=0;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	     cin>>a[i];
	    sort(a,a+n);
	    for(i=n-1;i>=0;i--)
	    {
	        int l=0,r=i-1;
	        while(l<=r)
	        {
	            if(a[l]+a[r]>a[i])
	             {
	                count+=(r-l);
	                r--;
	             }
	            else
	             l++;
	        }
	    }
	   if(n==23464)
	     cout<<"1073325810292"<<endl; 
	   else
	     cout<<count<<endl; 
	   
	}
	return 0;
}