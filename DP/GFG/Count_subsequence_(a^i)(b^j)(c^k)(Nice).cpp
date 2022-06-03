#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	 {
	     int i,acount=0,bcount=0,ccount=0;
	     string s;
	     cin>>s;
	     for(i=0;i<s.length();i++)
	      {
	          if(s[i]=='a')
	           acount=1+(2*acount);
	          else if(s[i]=='b')
	           bcount=acount+(2*bcount);
	          else
	           ccount=bcount+(2*ccount);
	      }
	     cout<<ccount<<endl; 
	 }
	return 0;
}