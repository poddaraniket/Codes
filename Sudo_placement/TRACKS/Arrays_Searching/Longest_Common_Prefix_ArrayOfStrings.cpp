#include<bits/stdc++.h>
using namespace std;

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        string s[n],p="",temp,c="";
        for(i=0;i<n;i++)
        {
            cin>>s[i];
        }
        p=s[0];
        for(i=1;i<n;i++)
         {
            temp=s[i]; 
            c="";
            for(j=0;j<p.length();j++)
            {
              if(p[j]==temp[j])
               c+=p[j];
              else
                break;
            }
           p=c;    
         }
        if(p!="") 
         cout<<p<<endl; 
        else
         cout<<"-1"<<endl;
    }
}