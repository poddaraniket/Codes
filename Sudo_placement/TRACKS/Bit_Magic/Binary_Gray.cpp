#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
	cin>>t;
	while(t--)
	{
	    int n,i=0,s=0,t,mask;
	    cin>>n;
	    while(n)
	    {
	        int t=pow(2,i);
	        mask=(n%2)^((n/2)%2);
	        //cout<<t<<" "<<mask<<endl;
	        s+=(t*mask);
	        n/=2;
	        i++;
	    }
	   cout<<s<<endl; 
	}
	return 0;
}
