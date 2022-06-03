#include <bits/stdc++.h>
using namespace std;

void balance(string s,int n,int zero,int one)
{
    if(one<zero)
     return;
    if(n==0)
     {
        cout<<s<<endl;
        return; 
     }
     
    balance(s+'1',n-1,zero,one+1);
    balance(s+'0',n-1,zero+1,one);
    
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	string s;
	balance(s,n,0,0);
	return 0;
}
