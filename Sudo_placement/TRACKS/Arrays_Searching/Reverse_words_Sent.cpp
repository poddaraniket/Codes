#include<bits/stdc++.h>
using namespace std;

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
	   string sent,s="";
	   cin>>sent;
	   int n=sent.length();
	   vector<string> v;
	   for(int i=0;i<n;i++)
	    {
	        if(sent[i]!='.')
	         s+=sent[i];
	        else
	        {
	         v.push_back(s);
	         s="";
	        }
	    }
	   v.push_back(s);
	   //cout<<v.size()<<endl;
	    //cout<<"*"<<endl;
	   for(int i=v.size()-1;i>=1;i--)
	    {
	        cout<<v[i]<<".";
	    }
	   cout<<v[0]<<endl; 
    }
}