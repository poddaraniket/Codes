#include<bits/stdc++.h>
using namespace std;


int valid(char *ip)    
{
int i=0,s=0,d=0;                                  
    if(ip[0]<48 && ip[0]>57)
       return 0;
     // string s="";
      while(ip[i]!='\0')
       {
           if(d>3)
            return 0;
           if(ip[i]=='0' && (ip[i+1]!='.' && ip[i+1]!='\0'))
            return 0;
           if(ip[i]=='.')    
            {
                //cout<<s<<endl;
                if(ip[i-1]<48 || ip[i-1]>57 || ip[i+1]<48 || ip[i+1]>57)
                 return 0;
               // cout<<s<<endl;  
                if(s<0 || s>255)
                  return 0;
                d++;
                s=0;
            }
          else if(ip[i]>=48 && ip[i]<=57)
           {
             s=(s*10)+(ip[i]-'0');  
             //cout<<s<<endl;
           }
          else 
            return 0;
         i++;    
       } 
     // cout<<s<<endl; 
      if(s<0 || s>255 || d<3)
       return 0;
      return 1;
}

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
      char s[10000];
      cin>>s;
      cout<<valid(s)<<endl;
    }
}