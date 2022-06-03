#include <bits/stdc++.h>
using namespace std;

bool comp(string s1,string s2)
{
    string ans1=s1+s2;
    string ans2=s2+s1;
    if(ans1>ans2)
     return true;
    return false; 
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<string> s(n);
	    for(int i=0;i<n;i++)
	     cin>>s[i];
	    //cout<<s[0]<<endl; 
	    sort(s.begin(),s.end(),comp); 
	    //cout<<"*";
	    for(int i=0;i<n;i++)
	      cout<<s[i];
	     cout<<endl; 
	}
	return 0;
}
