#include <bits/stdc++.h>
using namespace std;

void balance(string s,int n,int open)
{
    if(n%2!=0 && open==0)
     return;
    if(n==0)
     {
        if(open==0)
         cout<<s<<endl;
        return; 
     }
    if(open>n)
     return;
     
    balance(s+'(',n-1,open+1);
    
    if(open>0)
     balance(s+')',n-1,open-1);
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	string s;
	balance(s,n,0);
	return 0;
}
