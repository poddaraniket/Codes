#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MAX 1000000000000000 
 
 
int main() {
	// your code goes here
	ll n;
	cin>>n;
	ll sum=0,a[n];
	for(int i=0;i<n;i++)
	 {
	     cin>>a[i];
	 }
	sort(a,a+n); 
	ll c=1,big=(ll)1e15,ans=(ll)1e15; 
	while(1)
	 {
	    ll val=0,pw=1;
	    for(ll i=0;i<n;i++)
	     {
	         if(pw>=big)
	          {
	              val=-1;
	              break;
	          }
	         val+=abs(a[i]-pw);
	         pw*=c;
	     }
	    if(val==-1)
	     break;
	    ans=min(ans,val);
	    c++;
	 }
	cout<<ans<<endl;
	return 0;
}