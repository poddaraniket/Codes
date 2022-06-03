#include<bits/stdc++.h>

using namespace std;


string printMinIndexChar(string str, string patt)
{
    // your code here
    string t="";
	unordered_map<char,int> m;
	for(int i=0;i<patt.length();i++)
	{
	   m[patt[i]]=1; 
	}
	for(int i=0;i<str.length();i++)
	 {
	     if(m[str[i]]==1)
	      {
	          t+=str[i];
	          return t;
	      }
	 }
	return "$"; 
	// you don't need to print anything
	
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,s1;
        cin>>s>>s1;
        cout<<printMinIndexChar(s,s1)<<endl;
    }
}