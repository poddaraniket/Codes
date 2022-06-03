#include<bits/stdc++.h>
using namespace std;

vector<string> v;

void permute(string s,int l,int r)
{
    int i;
    if(l==r)
     v.push_back(s);
    else
     {
         for(i=l;i<=r;i++)
          {
              swap(s[l],s[i]);
              permute(s,l+1,r);
              swap(s[l],s[i]);
          }
     }
}

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
	   string st,temp="";
	   cin>>st;
	   int n=st.length();
	   permute(st,0,n-1);
	   for(int i=0;i<v.size();i++)
	    {
	        for(int j=i+1;j<v.size();j++)
	         {
	            if(v[i]>v[j])
	             {
	               temp=v[i];
	               v[i]=v[j];
	               v[j]=temp;
	             }
	         }
	    }
	  for(int i=0;i<v.size();i++)
	   cout<<v[i]<<" ";
	  cout<<endl; 
	  v.clear();
    }
}