#include <bits/stdc++.h>
using namespace std;

// int swapping(int a[],string s,string t,int loc)
// {
//     if(loc==s.length())
//     {
//       set<int> v,v1;
//       for(int i=0;i<s.length();i++)
//        {
//          v.insert(s[i]);
//          v1.insert(t[i]);
//        }
//       return max(v.size(),v1.size());   
//     }
//     else
//      {
//         if(s[loc]!=t[loc])
//          {
//             if(a[s[loc]-'a']==2 && a[t[loc]-'a']==1)
//              {
//               swap(s[loc],t[loc]);     
//               swapping(a,s,t,loc+1);
//              }
//             else
//              {
//                 a[s[loc]-'a']=1;
//                 a[t[loc]-'a']=2;
//                 swapping(a,s,t,loc+1);
//              }
//          }
//         else
//          {
//             swapping(a,s,t,loc+1);
//          }
//      }
// }

// int minimum_similarity(string s,string t,int n)
// {
//     int a[26]={0};
//     return swapping(a,s,t,0);
// }


int minimum_similarity(string s,string t,int n,int loc=0)
{
    if(loc==n)
     {
        set<int> v,v1;
        for(int i=0;i<n;i++)
         {
            v.insert(s[i]);
            v1.insert(t[i]);
         }
        return max(v.size(),v1.size()); 
     }
    string a,b;
    a=s;
    b=t;
    swap(a[loc],b[loc]);
    return min(minimum_similarity(a,b,n,loc+1),minimum_similarity(s,t,n,loc+1));
    //return temp;
}

int main(){
  int t; cin>>t;
  while (t--)
   {
       string s,t;
       int n;
       cin>>n;
       cin>>s>>t;
       cout<<minimum_similarity(s,t,n)<<endl;
   }
}