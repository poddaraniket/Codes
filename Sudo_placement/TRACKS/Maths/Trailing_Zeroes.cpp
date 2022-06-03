#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,s=0,i;
	    cin>>n;
	    for(i=5;n/i>=1;i*=5)
	    {
	       s+=(n/i);
	    }
	   cout<<s<<endl; 
	}
	return 0;
}