
#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--){
	   int n,k,c=0,i;
	   char find;
	   string s;
	   int a[26]={0};
	   cin>>s;
	   for(i=0;i<s.length();i++)
	    a[s[i]-'A']++;
	   //for(i=0;i<26;i++)
	   // cout<<a[i]<<endl;
	   cin>>k>>n>>find;
	   //cout<<a[find-]<<endl;
	   if(a[find-'A']==0)
	    cout<<"0"<<endl;
	   else
	    {
	        int t=n%(s.length());
	        //cout<<t<<endl;
	        for(i=0;i<t;i++)
	         {
	             if(s[i]==find)
	              c++;
	         }
	        cout<<((n/s.length())*a[find-'A'])+c<<endl;  
	    }
	  // cout<<a[find-'A']<<endl; 
	}
	
	return 0;
}