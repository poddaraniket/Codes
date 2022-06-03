#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long int x1,y1,x2,y2;
	    cin>>x1>>y1>>x2>>y2;
	    cout<<((x2-x1)*(y2-y1))+1<<endl;  //No. of paths != No. of different sums in path [eg--RRDD, no. of steps taken for it to convert to DDRR ]
	}
	return 0;
}