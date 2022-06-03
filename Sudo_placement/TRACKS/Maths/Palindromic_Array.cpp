#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,c=0;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	     cin>>a[i];
	    int l=0;
	    int r=n-1;
	    while(l<=r)
	    {
	       if(a[l]==a[r])
	        {
	            l++;
	            r--;
	        }
	       else
	        {
	            if(a[l]>a[r])
	             {
	                 a[r-1]=a[r]+a[r-1];
	                 r--;
	                 c++;
	             }
	            else
	             {
	                 a[l+1]=a[l]+a[l+1];
	                 l++;
	                 c++;
	             }
	        }
	    }
	 cout<<c<<endl;   
	}
	return 0;
}