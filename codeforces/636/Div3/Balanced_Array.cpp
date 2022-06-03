#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)
	 {
	    long long int n,p=2,od=1,i;
	    cin>>n;
	    if((n/2)%2!=0)
	     {
	         cout<<"NO"<<endl;
	     }
	    else
	     {
	         cout<<"Yes"<<endl;
	         for(i=1;i<=n/2;i++)
	          {
	              cout<<i*2<<" ";
	          }
	         for(i=1;i<(n/2);i++)
	          {
	              cout<<(i*2)-1<<" ";
	              //od+=2;
	          }
	         cout<<((i*2)-1)+(n/2)<<endl; 
	     }
	 }
}