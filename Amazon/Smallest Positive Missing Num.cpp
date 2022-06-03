#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    int a[n+1];
	    a[0]=-1;
	    for(i=1;i<=n;i++)
	     {
	       cin>>a[i];
	     }
	    for(i=1;i<=n;)
	     {
	         if(a[i]==i || a[i]>n || a[i]<=0)
	          i++;
	         else
	          {
	            int temp=a[i];
	            a[i]=a[temp];
	            //a[i]=a[a[i]];
	            a[temp]=temp;
	          }
	     }
	   // for(i=1;i<=n;i++)
	   //  cout<<a[i]<<" ";
	   // cout<<endl; 
	    for(i=1;i<=n;i++)
	     {
	         if(a[i]!=i)
	          break;
	     }
	    cout<<i<<endl; 
	}
	return 0;
}
