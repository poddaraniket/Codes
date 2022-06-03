#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b;
	    cin>>a>>b;
	    if((min(a,b)*2)>=max(a,b))
	     {
	         int f=min(a,b)*2;
	         cout<<f*f<<endl;
	     }
	    else
	     cout<<max(a,b)*max(a,b)<<endl;
	}
	return 0;
}