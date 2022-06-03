#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    double x,y,a,b;
	    cin>>x>>y;
	    if(x==1)
	     cout<<"0"<<endl;
	    else
	    {
	    a=log2(y);
	    b=log2(x);
	    //int up=ceil()
	    if(ceil(a/b)==floor(a/b))
	     cout<<"1"<<endl;
	    else
	     cout<<"0"<<endl;
	    }
	}
	return 0;
}