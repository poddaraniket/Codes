#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int n,long long int m)
{
    while(n!=m)
    {
        if(n>m)
         n-=m;
        else
         m-=n;
    } 
   return n;    
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,m;
	    cin>>n>>m;
	    long long int z=gcd(n,m);
	    //cout<<l<<endl;
	    cout<<(n*m)/z<<" "<<z<<endl;
	}
	return 0;
}