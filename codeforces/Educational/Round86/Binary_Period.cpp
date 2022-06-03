#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   int i,zero=0,one=0;
	   string s,t="";
	   cin>>s;
	   for(i=0;i<s.length();i++)
	    {
	     if(s[i]=='0')
	      zero=1;
	     else
	      one=1;
	    }
	   if(abs(zero-one)==0)
	    {
	       for(i=0;i<s.length()-1;i++)
	        {
	           t+=s[i]; 
	           if(s[i]=='0')
	             {
	                 if(s[i+1]=='0')
	                  t+='1';
	             }
	           else
	            {
	                if(s[i+1]=='1')
	                 t+='0';
	            }
	        }
	       t+=s[i]; 
	       cout<<t<<endl;
	    }
	   else
	     cout<<s<<endl;
	}
	return 0;
}