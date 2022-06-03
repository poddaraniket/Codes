#include <iostream>
using namespace std;

bool match(string sent,int i,string patt,int j,auto &mp)
{
    int n=sent.length();
    int m=j.length();
    if(n<m)
     return false;
    if(i==n && j==m)
     return true;
    if(i==n || j==m)
     return false;
    char curr=patt[j];
    if(mp.find(curr)!=mp.end())
     {
        string s=mp[curr];
        int k=s.length();
        if(sent.substr(i,k)!=s)
         return fasle;
        return match(sent,i+k,patt,j+1,mp); 
     }
    for(int k=1;k<=n-i;k++)
    {
        mp[curr]=sent.substr(i,k);
        if(match(sent,i+k,patt,j+1,mp))
         return true;
        mp.erase(curr); 
    }
}

int main() {
	// your code goes here
	string sent,patt;
	cin>>sent;
	cin>>patt;
	unordered_map<char,string> mp;
	if(match(sent,0,patt,0,mp))
	 {
	     for(auto it=mp.begin;it!=mp.end();it++)
	      {
	          cout<<it->first<<": "<<it->second<<endl;
	      }
	 }
	return 0;
}
