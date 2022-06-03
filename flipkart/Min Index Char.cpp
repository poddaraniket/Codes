#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string str,patt;
	    cin>>str;
	    cin>>patt;
	    int loc[26];
	    memset(loc,-1,sizeof(loc));
	    for(int i=0;i<str.length();i++)
	     {
	         if(loc[str[i]-'a']==-1)
	          loc[str[i]-'a']=i;
	     }
	    int mini=1000000,loc_patt=-1; 
	    for(int j=0;j<patt.length();j++)
	     {
	         if(loc[patt[j]-'a']!=-1)
	          {
	             if(mini>loc[patt[j]-'a'])
	              {
	                  mini=loc[patt[j]-'a'];
	                  loc_patt=j;
	              }
	          }
	     }
	    if(loc_patt==-1)
	     cout<<"$"<<endl;
	    else
	     cout<<patt[loc_patt]<<endl;
	}
	return 0;
}