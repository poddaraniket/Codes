#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,k,temp,i,c=0,mini=10000000000;
	    cin>>n>>k;
	    //mini=n;
	    if(k>=n)
	     cout<<"1"<<endl;
	    else
	     {
	         //cout<<"*"<<endl;
	         temp=floor(sqrt(n));
	         //cout<<temp<<endl;
	         for(i=min(temp,k);i>=1;i--)
	          {
	             if(n%i==0)
	              {
	                  if((n/i)<=k)
	                   mini=min(min((n/i),i),mini);
	                  else
	                   mini=min((n/i),mini);
	              }
	          }
	         cout<<mini<<endl; 
	     }
	}
	return 0;
}