#include<bits/stdc++.h>
using namespace std;
 
int main() {
  string s,temp;
  cin>>s;
  int len,i,c=0,f=0,z=0;
  len=s.size();
  for(i=0;i<len-1;i++)
   {
     temp="";
     temp+=s[i];
     temp+=s[i+1];
     if(temp=="AB" && c==0)
      {
        c=1;
        i++;
      }
     if(c==1)
      {
        if(temp=="BA")
         f=1;
      }
    if(c==1 && f==1)
     {
       z=1;
       break;
     }   
   }
  if(z==1)
   cout<<"YES"<<endl;
  else
   {
     c=0;
     f=0;
     for(i=0;i<len-1;i++)
     { 
      temp="";
      temp+=s[i];
      temp+=s[i+1];
      if(temp=="BA" && f==0)
       {
        f=1;
        i++;
       }
      if(f==1)
       {
        if(temp=="AB")
         c=1;
       }
      if(c==1 && f==1)
       {
        z=1;
        break;
       }   
     }
    if(z==1)
     cout<<"YES"<<endl;
    else
     cout<<"NO"<<endl;  
   }
}