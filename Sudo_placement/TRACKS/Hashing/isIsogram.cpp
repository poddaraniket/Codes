#include<bits/stdc++.h>

using namespace std;

bool isIsogram(string s)
{
    //Your code here
    //int c=0;
    map<char,int> mp;
    for(int i=0;i<s.length();i++)
     {
        if(mp[s[i]]==0)
         mp[s[i]]++;
        else
         {
            return false;
         }
     }
    return true; 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	  string n;
	  cin>>n;
	  cout<<isIsogram(n)<<endl;
	}
}