#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int maxi=0;
	    string s;
	    cin>>s;
	    stack<int> st;
	    st.push(-1);
	    //map<int,int> mp;
	    for(int i=0;i<s.length();i++)
	     {
	         if(st.top()==-1)
	         {
	          st.push(i);
	          continue;
	         }
	         if(s[i]=='(')
	          st.push(i);
	         else
	          {
	              if(s[st.top()]=='(')
	               {
	                   st.pop();
	                   maxi=max(maxi,i-st.top());
	               }
	              else
	               st.push(i);
	          }
	     }
	    cout<<maxi<<endl; 
	}
	return 0;
}