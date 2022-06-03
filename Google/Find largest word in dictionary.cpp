#include <bits/stdc++.h>
using namespace std;


bool isSubsequence(string word,string dictionary)
{
    int i=0,j=0;
    while(i<word.length() && j<dictionary.length())
     {
        if(word[i]==dictionary[j])
         j++;
        i++; 
     }
    return (j==dictionary.length()); 
}

string find(string word,vector<string> dict)
{
    int length=0;
    string result="";
    for(int i=0;i<dict.size();i++)
     {
        if(length<dict[i].length() && isSubsequence(word,dict[i]))
         {
            result=dict[i];
            length=result.length();
         }
     }
    return result; 
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int x;
	    cin>>x;
	    vector<string> dict(x);
	    for(int i=0;i<x;i++)
	     cin>>dict[i];
	    string word;
	    cin>>word;
	    cout<<find(word,dict)<<endl;
	}
	return 0;
}
