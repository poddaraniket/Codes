#include <bits/stdc++.h>
using namespace std;

int findlength(string sent)
{
    int maxi=0;
    stack<int> s;
    s.push(-1);
    for(int i=0;i<sent.length();i++)
     {
        if(sent[i]=='(')
         s.push(i);
        else
         {
            s.pop();
            if(s.empty())
             {
                s.push(i);
                continue;
             }
            maxi=max(maxi,i-s.top()); 
         }
     }
    return maxi; 
}

int main() {
    cout<<findlength("(()())(()")<<endl;
	return 0;
}
