#include <bits/stdc++.h>
using namespace std;

void rotate(string s,int i,int n)
{
    if(i==n-1)
    {
     cout<<s<<" ";    
     return;
    }
    for(int j=i;j<n;j++)
     {
        swap(s[i],s[j]);
        rotate(s,i+1,n);
        // cout<<s<<endl;
        swap(s[i],s[j]);  //Backtracking
     }
}

int main() {
	// your code goes here
	string s="ABC";
	rotate(s,0,s.length());
	return 0;
}
