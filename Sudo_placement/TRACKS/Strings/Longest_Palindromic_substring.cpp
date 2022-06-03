#include<bits/stdc++.h>
using namespace std;

string palin(string s)
{
   int i,j,n,d,c=0; 
   string fro="",rev="";
   n=s.length();
   for(d=n;d>=2;d--)
     {
          //cout<<d<<endl;
      for(i=0;i<=n-d;i++)
        {
                //cout<<i<<endl;
         fro="";
         rev="";
         int k=i+d;
         for(j=i;j<k;j++)
          {
            fro+=s[j];
            rev=s[j]+rev;
          }
               // int x=fro.compare(rev); 
         if(fro==rev)
           return fro;        
       }
     }
     return "#$@";
}

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
      string s,h;
      cin>>s;
      h=palin(s);
      if(h=="#$@")
       cout<<s[0]<<endl;
      else
       cout<<h<<endl;
    }
}