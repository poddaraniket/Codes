#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long int old_a,diff;
	    cin>>old_a>>diff;
	    long long int a=max(old_a,diff);
	    long long int s=a+diff;
	    long long int b=(s/2)+(s%2);
	    long long int new_a=(2*b)-diff;
	    cout<<new_a-old_a<<endl;
	}
	return 0;
}