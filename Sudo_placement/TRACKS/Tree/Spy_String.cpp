#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
	    int i,n,m,c=0,k,l;
	    char j;
	    cin>>n>>m;
	    string s[n],ans;
	    for(i=0;i<n;i++)
	     cin>>s[i];
	    ans=s[0];
	    for(i=0;i<m;i++)
	     {
	         char temp=ans[i];
	         for(j='a';j<='z';j++)
	          {
	              ans[i]=j;
	              bool flag=true;
	              for(k=0;k<n;k++)
	               {
	                    string sent=s[k];    
	                    int count=0;
	                    for(l=0;l<m;l++)
	                      {
	                         if(sent[l]!=ans[l])
	                         count++;
	                      }
	                    if(count>1)
	                     {
	                        flag=false;
	                        break;
	                     }
	                }
	              if(flag==true)
	               {
	                 c=1;
	                 break;
	               }
	          }
	        if(c==1)
	          break;
	        ans[i]=temp; 
	     }
	  if(c==1) 
	    cout<<ans<<endl;
	  else
	    cout<<"-1"<<endl;
	}
  return 0;
}