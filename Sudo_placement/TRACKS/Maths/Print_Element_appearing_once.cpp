#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,num,s=0;
	    cin>>n;
	    map<int,int> mp;
	    for(int i=0;i<n;i++)
	     {
	        cin>>num;
	        s^=num;
	     }
	    cout<<s<<endl; 
	}
	return 0;
}