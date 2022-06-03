#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long long int x,y,a,b;
	    cin>>x>>y;
	    cin>>a>>b;
	    long long int diff=abs(x-y);
	    cout<<min((x+y)*a,(diff*a)+(max(x,y)-diff)*b)<<endl;
	}
	return 0;
}