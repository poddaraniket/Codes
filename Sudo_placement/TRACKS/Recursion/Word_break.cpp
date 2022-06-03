#include <bits/stdc++.h>
using namespace std;

int dictcompare(string a,vector<string> &b)
{
    for(int i=0;i<b.size();i++)
    {
        if(b[i]==a)
         return true;
    }
   return false;    
}

int wordBreak(string A,vector<string> &B)
{
    if(A.length()==0)
     return true;
    for(int i=1;i<=A.length();i++)
      {
        if(dictcompare(A.substr(0,i),B) && wordBreak(A.substr(i,A.length()),B))
          return true;
      }
    return false; 
}

int main()
 {
  int t;
  cin>>t;
  while(t--)
  {
    int n,i;
    cin>>n;
    vector<string> v;
    for(i=0;i<n;i++)
     {
         string word;
         cin>>word;
         v.push_back(word);
     }
    string sent;
    cin>>sent;
    cout<<wordBreak(sent,v)<<endl;;
  }
	return 0;
}