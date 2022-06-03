// YES -> if we can survive for frst 6 days -> If yes (Min Buy=ceil(total food req/food buy per day)
// NO


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int s,n,m;
	cin>>s>>n>>m;
	if(s>6)
	 {
	     if(7*m<=n*6)
	      cout<<"YES "<<ceil((double)m*s/(double)n)<<endl;
	     else
	      cout<<"NO"<<endl;
	 }
	else
	 {
	     if(n>m)
	      cout<<"YES "<<ceil((double)m*s/(double)n)<<endl;
	     else
	      {
	          cout<<"NO"<<endl;
	      }
	 }
}
