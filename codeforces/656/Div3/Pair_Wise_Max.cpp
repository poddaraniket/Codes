#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long int x,y,z;
	    cin>>x>>y>>z;
	    if(x==y && y==z)
	     {
	         cout<<"YES"<<endl;
	         cout<<x<<" "<<x<<" "<<x<<" "<<endl;
	     }
	    else if(x!=y && x!=z && y!=z) 
	     {
	          cout<<"NO"<<endl;
	     }
	    else
	     {
	         if(x==z && x>y)
	          {
	              cout<<"YES"<<endl;
	              cout<<y<<" "<<y<<" "<<x<<endl;
	          }
	         else if(x==y && x>z)
	          {
	               cout<<"YES"<<endl;
	               cout<<z<<" "<<z<<" "<<x<<endl;
	          }
	          else if(z==y && y>x)
	          {
	               cout<<"YES"<<endl;
	               cout<<x<<" "<<x<<" "<<y<<endl;
	          }
	         else
	          cout<<"NO"<<endl;
	     }
	}
	return 0;
}