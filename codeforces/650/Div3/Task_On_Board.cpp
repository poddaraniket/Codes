#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n;
	    cin>>n;
	    int b[n+2];
	    char t[n+2];
	    //set<char> st;
	    unordered_map<char,ll> mp;
	    sort(s.begin(),s.end());
	    for(int i=0;i<s.length();i++)
	     {
	       mp[s[i]]++;
	     }
	    int j=s.length()-1;
	    for(int i=1;i<=n;i++)
	     {
	         cin>>b[i];
	     }
	    while(true)
	     {
	         vector<ll> v;
	         ll count=0;
	         for(int i=1;i<=n;i++)
	          {
	              if(b[i]==0)
	               {
	                 count++;    
	                 v.push_back(i);
	               }
	          }
	         if(count==0)
	          break;
	         if(mp[s[j]]<count)
	          {
	              j-=mp[s[j]];
	              continue;
	          }
	         int pointer=j;
	         j-=mp[s[j]];
	         for(int i=1;i<=n;i++)
	         {
	             if(b[i]==0)
	              {
	                  t[i]=s[pointer];
	                  b[i]=-1;
	              }
	             else
	              {
	                  for(int k=0;k<v.size();k++)
	                   {
	                       b[i]=b[i]-abs(i-v[k]);
	                   }
	              }
	         }
	     }
	    for(int i=1;i<=n;i++)
	     cout<<t[i];
	    cout<<endl; 
	}
	return 0;
}