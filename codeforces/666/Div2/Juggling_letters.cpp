#include <bits/stdc++.h>
using namespace std;
 
bool possible(int freq[],int n)
{
    for(int i=0;i<26;i++)
     {
         if(freq[i]==0)
          continue;
         if(freq[i]%n!=0) 
          return false;
     }
    return true; 
}
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int freq[26]={0};
	    string sent;
	    for(int i=0;i<n;i++)
	     {
	        cin>>sent;
	        for(int j=0;j<sent.length();j++)
	         freq[sent[j]-'a']++;
	     }
	   if(possible(freq,n))
	    cout<<"Yes"<<endl;
	   else
	    cout<<"No"<<endl;
	}
	return 0;
}