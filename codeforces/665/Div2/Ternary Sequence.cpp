#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int ax,ay,az,bx,by,bz;
	    cin>>ax>>ay>>az;
	    cin>>bx>>by>>bz;
	    bz-=min(bz,ax);
	    //get the max that is by seeing 2 in A and 1 in B 
	    int pos=2*min(az,by);
	    //minimze the restrict
	    // by combining 2 of B with 0 of A and 2 of left over az
	    // rest will automatically combine with 0
	    // so u combine minimum of 1 of A with 2 of B that will give the negative value
	    az-=min(az,by);
	    bz-=min(bz,az);
	    int neg=2*min(bz,ay);
	    cout<<pos-neg<<endl;
	}
	return 0;
}
