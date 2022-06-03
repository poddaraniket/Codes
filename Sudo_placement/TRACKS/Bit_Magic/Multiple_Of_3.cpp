#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
	cin>>t;
	while(t--)
	{
	    int i=0,n,ev=0,od=0;
	    string s;
	    cin>>s;
	    n=s.length();
	    //cout<<s[0]<<endl;
	    while(i<n)
	    {
	       if(s[i]-'0'==1)
	        {
	            //cout<<"*"<<i<<endl;
	            if(i%2==0)
	             ev++;
	            else
	             od++;
	        }
	       i++;
	    }
	   //cout<<abs(ev-od)<<endl; 
	   if(abs(ev-od)%3==0) 
	    cout<<"1"<<endl;
	   else
	    cout<<"0"<<endl;
	}
	return 0;
}
