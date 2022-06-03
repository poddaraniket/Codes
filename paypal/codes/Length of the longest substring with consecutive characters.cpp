#include <bits/stdc++.h>
using namespace std;

int largestSubStr(string str,int n)
{
    int l=0,r=1,len=1;
    while(r<n)
     {
        if(str[r]-str[r-1]!=1)
         {
        //  cout<<str[l]<<" "<<str[r]<<endl;         
          len=max(r-l,len); 
          l=r;
        } 
        r++;
     }
    return max(r-l,len); 
}


int main() {
	// your code goes here
	string str = "abcabcabcdef";
    int n = str.length();
    cout << (largestSubStr(str, n));
	return 0;
}
