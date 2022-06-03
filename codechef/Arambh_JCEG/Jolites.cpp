#include<bits/stdc++.h>
using namespace std;

int main() {
     int t,i;
     cin>>t;
     while(t--)
      {
        int c=0,n;
        cin>>n;
        string s,temp="";
        cin>>s;
        for(i=0;i<n-3;i++)
         {
           //cout<<s[i]<<s[i+1]<<s[i+2]<<s[i+3]<<endl;
           temp="";
           temp+=s[i];
           temp+=s[i+1];
           temp+=s[i+2];
           temp+=s[i+3];
           //cout<<temp<<endl;
           if(temp=="JGEC")
            c++;
         }
        cout<<c<<endl; 
      }
}