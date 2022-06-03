// C++ program to evaluate value of a postfix expression
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// The main function that returns value of a given postfix expression
int evaluatePostfix(string &str)
{
    // Your code here
    stack<int> s;
    for(int i=0;i<str.length();i++)
     {
        if(s.empty() || str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/')
         s.push(str[i]-'0');
        else
         {
            int t=s.top();
            s.pop();
            int t1=s.top();
            s.pop();
            if(str[i]=='+')
             {
                int cal=t1+t;
                s.push(cal);
                //cout<<cal<<" ";
             }
            else if(str[i]=='-')
             {
                int cal=t1-t;
                s.push(cal);
                //cout<<cal<<" ";
             }
            else if(str[i]=='*')
             {
                int cal=t1*t;
                s.push(cal);
                //cout<<cal<<" ";
             }
            else
             {
                int cal=t1/t;
                s.push(cal);
                //cout<<cal<<" ";
             } 
         }
     }
    return s.top(); 
}


// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string str;
        cin>>str;
    
    cout<<evaluatePostfix(str)<<endl;
    }
    return 0;
}
  // } Driver Code Ends