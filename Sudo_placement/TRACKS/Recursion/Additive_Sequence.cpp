#include <bits/stdc++.h>
using namespace std;

bool isValid(string num)
{
    if(num.length()>1 && num[0]=='0')
     return false;
    return true; 
}

int val(string a,int pos)
{
    if(pos<0)
     return 0;
    else
     return (a[pos]-'0');
}

string sumation(string a,string b)          //can't use stoi() for addition purpose as the length of string is too much 
{
    int i=a.length()-1;
    int j=b.length()-1;
    int carry=0;
    string s="";
    while(i>=0 || j>=0)
     {
        int t=val(a,i)+val(b,j)+carry;
        s+=(t%10+'0');
        carry=t/10;
        i--;
        j--;
     }
    if(carry)
     s+=(carry+'0');
    reverse(s.begin(),s.end()); 
    //cout<<s<<endl;
    return s; 
}

bool checkAddition(string a,string b,string c)
{
    if(!isValid(a) || !isValid(b))     // returns only if the start of string contain 0 
     return false;
    string sum=sumation(a,b);
    if(sum==c)     //return only if the sum of a&b will take the rest of string as sum
     return true;
    if(sum.size()>=c.size() || sum!=c.substr(0,sum.size())) 
     return false;
    else
      {
          //cout<<a<<" "<<b<<endl;
            /*a+b has taken sum part of the leftover string
             so it will nw take b as frst string the sum as second string and the leftover nt as sum will 
             be used to see if the sum is there of the new a&b*/
            return checkAddition(b,sum,c.substr(sum.size()));  
      }
}

bool isAdditiveSequence(string s)
{
    int len=s.length();
    for(int i=1;i<(len/2);i++)
    {
        for(int j=1;j<(len-i)/2;j++)
        {
            //it will form various combination of strings for the sum must be substring 
            if(checkAddition(s.substr(0,i),s.substr(i,j),s.substr(i+j)))
             return true;
        }
    }
    return false;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
   {
    //int n;
    //cin>>n;
    string s;
    cin>>s;
    cout<<isAdditiveSequence(s)<<endl;
   }
    return 0;
}