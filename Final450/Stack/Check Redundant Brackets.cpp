#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    stack<char> st;
	for(int i=0;i<s.length();i++){
	    if(s[i]==')')
	     {
	        char top=st.top();
	        st.pop();
	        bool flag=true;
	        while(!st.empty() && top!='(')
	         {
	            if(top=='+' ||top=='-' ||top=='*' ||top=='/')
	             {
	                flag=false;      
	             }
	            top=st.top();
	            st.pop();
	         }
	        if(flag==true){
	            return true;
	        }  
	     }
	    else{
	        st.push(s[i]);
	    }
	}
	return false;
}

int main() {
	// your code goes here
	string s;
	cin>>s;
	cout<<check(s)<<endl;
	return 0;
}
