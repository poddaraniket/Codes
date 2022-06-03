#include<bits/stdc++.h>
using namespace std;

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
       int i,c=0;
       int n;
       cin>>n;
	   string s;
	   cin>>s;
	   for(i=0;i<n;i++)
	    {
	        if(s[i]=='1')
	         c++;
	    }
	   if(c>1) 
	    cout<<(c*(c-1))/2<<endl; 
	   else
	    cout<<"0"<<endl;
    }
}