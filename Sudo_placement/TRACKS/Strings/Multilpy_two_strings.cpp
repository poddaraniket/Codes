#include<bits/stdc++.h>
using namespace std;
 
string multiplyStrings(string , string );
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	
    	cout<<multiplyStrings(a,b)<<endl;
    }
     
}// } Driver Code Ends
/*You are required to complete below function */

string mul(string s1,char a, string sent)
{
    //cout<<"*"<<endl;
    int carry=0;
    int d=a-'0';
    for(int i=s1.length()-1;i>=0;i--)
     {
        int m=(s1[i]-'0')*d;
        m+=carry;
        int mod=m%10;
        carry=m/10;
        sent=(char)(mod+48)+sent;
     }
    if(carry!=0) 
      sent=(char)(carry+48)+sent;  
    return sent;
}

string add(vector<string> s,int len)
{
    //cout<<len<<endl;
    string play="";
    string temp=s[0];
    int carry=0;
    for(int i=1;i<s.size();i++)
     {
        string s1=s[i]; 
        play="";
        for(int j=len-1;j>=0;j--)
         {
             int a=temp[j]-'0';
             int b=s1[j]-'0';
             int plus=a+b;
             plus+=carry;
             int mod=plus%10;
             carry=plus/10;
             play=(char)(mod+48)+play;
         }
        if(carry!=0) 
          play=(char)(carry+48)+play;
        temp=play;
        //cout<<temp<<endl;
     }
    return temp; 
}

string multiplyStrings(string s1, string s2) {
   //Your code here
   int count=0;
   if(s1[0]=='-')
    {
     count++;
     s1=s1.substr(1);
    }
   if(s2[0]=='-')
    {
        count++;
        s2=s2.substr(1);
    }
   string s="";
   int i,j;
   vector<string> v;
   v.push_back("0");
   for(i=s2.length()-1;i>=0;i--)
    {
       s="";    
       for(j=1;j<=(s2.length()-1)-i;j++)
        s+='0';
       v.push_back(mul(s1,s2[i],s));
    }
   int len=v[v.size()-1].length();
   for(int i=0;i<v.size();i++)
   {
       int len1=v[i].length();
       for(int j=0;j<len-len1;j++)
        {
            v[i]='0'+v[i];
        }
      //cout<<v[i]<<endl;    
   }
   string res= add(v,len);
   int loc=-1;
   for(i=0;i<res.length()-1;i++)
    {
        if(res[i]=='0')
         loc=i;
        else
         break;
    }
   res=res.substr(loc+1); 
   //cout<<res<<endl;
   if(count==1 && res!="0")
    res='-'+res;
   return res;    
}