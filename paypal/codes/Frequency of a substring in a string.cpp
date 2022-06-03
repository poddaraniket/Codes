#include <bits/stdc++.h>
using namespace std;

int countFreq(string pat,string txt)
{
    int r=pat.length(),ans=0;
    string cmp=txt.substr(0,r);
    while(r<=txt.length())
     {
        if(cmp.compare(pat)==0){
         ans++;
        }
        cmp.erase(cmp.begin());
        cmp+=txt[r];
        r++;
     }
    return ans; 
}

int main()
{
   string txt = "aaaaa";
   string pat = "aa";
   cout << countFreq(pat, txt);
   return 0;
}