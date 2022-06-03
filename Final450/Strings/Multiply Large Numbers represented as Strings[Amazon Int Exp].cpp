#include <bits/stdc++.h>
using namespace std;

string multiply(string s1,string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    int size=n1+n2;
    int res[size]={0};
    int p=0;
    for(int i=n2-1;i>=0;i--)
     {
        int m=s2[i]-'0';
        int carry=0;
        int temp=size-(++p);
        for(int j=n1-1;j>=0;j--)
         {
            int a=s1[j]-'0';
            int pro=(a*m)+carry;
            int sum=pro%10;
            carry=pro/10;
            int val=res[temp]+sum;
            res[temp--]=val%10;
            carry+=val/10;
         }
        if(carry>0)
         res[temp]=carry;
     }
    string ans="";
    int f=0;
    for(int i=0;i<size;i++){
      if(res[i]!=0)
       f=1;
      if(res[i]==0 && f!=0)
       ans+=char(res[i]+'0');
      else if(res[i]!=0)
       ans+=char(res[i]+'0');
    }
    return ans; 
}

int main()
{
    string str1 = "1235421415454545454545454544";
    string str2 = "1714546546546545454544548544544545";
     
    if((str1.at(0) == '-' || str2.at(0) == '-') &&
        (str1.at(0) != '-' || str2.at(0) != '-' ))
        cout<<"-";
 
 
    if(str1.at(0) == '-')
        str1 = str1.substr(1);
   
    if(str2.at(0) == '-')
        str2 = str2.substr(1);
 
    cout<<multiply(str1, str2);
    return 0;
}