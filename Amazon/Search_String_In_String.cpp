#include <bits/stdc++.h>
using namespace std;

int place(string haystack,string needle)
{
    int len1=haystack.length();
    int len2=needle.length();
    int loc=0,p=0;
    for(int i=0;i<len1;i++)
     {
        if(haystack[i]==needle[p])
         {
            if(p==0)
             loc=i;
            p++; 
         }
        else
         p=0;
        if(p==len2)
         return loc;
     }
    return -1; 
}

int main() {
	// your code goes 
	int t;
	cin>>t;
	while(t--)
	{
      string haystack,needle;
      cin>>haystack>>needle;
      cout<<place(haystack,needle)<<endl;
	}
	return 0;
}
