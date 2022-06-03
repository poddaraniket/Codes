#include<bits/stdc++.h>
using namespace std;

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
      string s,t,p="",ans;
      cin>>s>>t;
     // cout<<s.length()<<" "<<t.length()<<endl;
      int n,m,i,j=0,maxi=0,loc,loci;
      for(i=0;i<t.length();i++)
       {
           if(t[i]==s[j])
            {
                if(j==0)
                 loc=i;
                p+=t[i];
                j++;
            }
           else
             {
                j=0;
                if(p.length()>maxi)
                 {
                     loci=loc;
                     maxi=p.length();
                     ans=p;
                 }
                p=""; 
             }
       }
      if(p.length()>maxi)
       {
           loci=loc;
           maxi=p.length();
           ans=p;
       }
      if(maxi>0) 
       cout<<loci<<" "<<ans<<endl; 
      else 
       cout<<"-1"<<endl;
    }
}