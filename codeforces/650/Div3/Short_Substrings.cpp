#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    string b,a="";
	    cin>>b;
	    char temp;
	    a+=b[0];
	    //b=b.substr(1);
	    temp=b[b.length()-1];
	    for(int i=1;i<b.length()-1;i+=2)
	     {
	         a+=b[i];
	     }
	    a+=temp;
	    cout<<a<<endl;
	}
	return 0;
}