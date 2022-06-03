#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,count=0;
	    cin>>n;
	    while(n)
	     {
	        count++;
	        n=n&(n-1);
	     }
	    cout<<count<<endl; 
	}
	return 0;
}