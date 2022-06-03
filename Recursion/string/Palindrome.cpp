#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s,int low,int high)
{
    if(low>=high)
     return true;
    if(s[low]!=s[high])
     return false;
    palindrome(s,low+1,high-1); 
}

int main() {
	// your code goes here
	string s;
	cin>>s;
	cout<<palindrome(s,0,s.length()-1)<<endl;
	return 0;
}
