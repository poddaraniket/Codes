#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;

int main() {
	// your code goes here
	string s="Geeks For Geeks";
	string temp="";
    for(int i=0;i<s.length();i++)
	 {
	     if(s[i]!=' ')
	      {
	          temp+=s[i];
	      }
	     else 
	     {
	         mp[temp]++;
	         temp="";
	     }
	 }
	mp[temp]++; 
	for(auto it=mp.begin();it!=mp.end();it++)
	 cout<<it->first<<" "<<it->second<<endl;
	return 0;
}
