
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,q,temp;
	     cin>>n>>q;
	     string s;
	     temp=n;
	     cin>>s;
	     while(q--)
	      {
	          int typ,k;
	          cin>>typ>>k;
	          if(typ==2)
	           {
	             cout<<s[(temp+k)%n]<<endl;  
	           }
	          else
	            {
	                temp-=(k%n);
	                if(temp<0)
	                 temp+=n;
	            }
	      }
	 }
}