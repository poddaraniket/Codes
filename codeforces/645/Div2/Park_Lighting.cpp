#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     float n,m;
	     cin>>n>>m;
	     //float t=n*m;
	     //cout<<<<t<<endl;
	     cout<<fixed<<setprecision(0)<<ceil((n*m)/2.0)<<endl;
	 }
	return 0;
}