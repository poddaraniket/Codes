#include <bits/stdc++.h>
using namespace std;

set<string> st;

void lexico(string word,string s,int n)
{
   if(n==0)
    {
       // sort(word.begin(),word.end());
        st.insert(word);
        return;
    }
   for(int i=0;i<s.length();i++)
    {
        lexico(word+s[i],s,n-1);
    }
}

int main() {
	// your code goes here
	string s;
	cin>>s;
	int n=s.length();
	sort(s.begin(),s.end());
	lexico("",s,n);
	for(auto it=st.begin();it!=st.end();it++)
	  cout<<*it<<" ";
	return 0;
}
