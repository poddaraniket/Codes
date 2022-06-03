#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string str)
{
    int start=0;
    int freq[26];
    memset(freq,-1,sizeof(freq));
    int maxi=0;
    for(int end=0;end<str.length();end++)
     {
        if(freq[str[end]-'a']!=-1)
         {
           // cout<<end<<endl; 
            maxi=max(maxi,end-start);
            start=max(freq[str[end]-'a']+1,start);
            
         }
        freq[str[end]-'a']=end;
     }
    return maxi;  
}

int main()
{
    //ABDEFGABEF
    string str = "abdefgabef";
    cout << "The input string is " << str << endl;
    int len = longestUniqueSubsttr(str);
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len;
    return 0;
}