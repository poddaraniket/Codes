#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i=0,s=0;
	    cin>>n;
	    if(n==0)
	     cout<<"0"<<endl;
	    else
	    {
	    int t=ceil(log2(n));
	    int a[t+1]={0},b[t];
	    while(n)
	    {
	       a[t-i]=n%2;
	       n/=2;
	       i++;
	    }
	    b[0]=a[0];
	    for(i=1;i<=t;i++)
	     {
	       b[i]=b[i-1]^a[i];
	     }
	    for(i=t;i>=0;i--)
	     {
	         s+=(pow(2,t-i)*b[i]);
	     }
	    cout<<s<<endl; 
	    }
	}
	return 0;
}
