
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,k,mod;
	     cin>>n>>k;
	     if(k==0)
	      {
	          if(n%2!=0)
	           cout<<"Yes"<<endl;
	          else
	           cout<<"No"<<endl;
	      }
	     else
	       {
	           mod=floor(log2(n));
	           while(k<mod)
	            {
	             n-=pow(2,mod);
	             if(n<=0)
	              break;
	             mod=floor(log2(n));
	            }
	          if(k==mod)
	           cout<<"Yes"<<endl;
	          else
	           cout<<"No"<<endl;
	       }
	 }
}