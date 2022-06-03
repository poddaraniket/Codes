#include <bits/stdc++.h>
using namespace std;
 
string check(string s,int n,int k)
{
   int cnt0=0,cnt1=0;    
   char temp[k];
   memset(temp,'?',sizeof(temp));
   for(int i=0;i<k;i++)
    {
        if(s[i]=='0' || s[i]=='1')
         temp[i]=s[i];
        for(int j=i;j<n;j+=k)
         {
            if(s[j]!='?')
             {
                if(temp[i]!='?') 
                 {
                   if(temp[i]!=s[j])
                   {
                     //cout<<i<<" "<<j<<endl;  
                     return "NO";
                   }
                 }
                else
                  temp[i]=s[j]; 
             }
         }
    }
   //cout<<"*"<<endl;    
   for(int i=0;i<k;i++)
    {
        if(temp[i]=='1')
         cnt1++;
        else if(temp[i]=='0')
         cnt0++;
    }
   if(cnt0>(k/2) || cnt1>(k/2))
    return "NO";
   return "YES";    
}
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    string s;
	    cin>>s;
	    cout<<check(s,n,k)<<endl;
	}
	return 0;
}