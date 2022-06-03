#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n,i,temp;
	cin>>n;
	string s[n];
	map<string,int> mp;
	for(i=0;i<n;i++)
	 {
	     cin>>s[i];
	     mp[s[i]]++;
	 }
    for(i=n-1;i>=0;i--)
     {
        mp[s[i]]--;
        if(mp[s[i]]!=0)
         s[i]+=to_string(mp[s[i]]);
        else
         s[i]="OK";
     }
    for(i=0;i<n;i++)
     cout<<s[i]<<endl;
}