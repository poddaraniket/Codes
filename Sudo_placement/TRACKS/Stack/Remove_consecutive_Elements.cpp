#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return string after removing consecutive duplicates

// Function to remove pair of characters
string removePair(string str){
    // Your code here
    stack<char> s;
    string tmp="";
    int a[26]={0};
    for(int i=0;i<str.length();i++)
    {
     if(s.empty() || s.top()!=str[i])
     {
        s.push(str[i]);  
     }
    else
      s.pop();
    }
    while(!s.empty())
    {
        tmp=s.top()+tmp;
        s.pop();
    }
    return tmp;
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        
        string ans = removePair (s);
        
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}  // } Driver Code Ends