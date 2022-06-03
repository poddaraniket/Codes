#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
   {
     string str1,str2;
     cin>>str1>>str2;
     int k;
     cin>>k;
     if(str1.length()==str2.length())
      {
        int i,sum=0;  
        int s[26]={0};
        int s1[26]={0};
        for(i=0;i<str1.length();i++)
         {
            s[str1[i]-'a']++;
            s1[str2[i]-'a']++;
         }
        for(i=0;i<26;i++)
         {
            sum+=abs(s[i]-s1[i]);
         }
        if((sum/2)<=k)
         cout<<"1"<<endl;
        else
         cout<<"0"<<endl;
      }
     else
      cout<<"0"<<endl;
   }
	return 0;
}