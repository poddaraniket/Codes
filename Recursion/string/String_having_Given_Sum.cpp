#include <bits/stdc++.h>
using namespace std;

void Digits(string s,int n,int sum,int count)
{
   if(n==0)
    {
        if(count==sum)
         cout<<s<<" ";
        return; 
    }
   for(int i=0;i<9;i++)
    {
        if(s.length()==0 && i!=0)
         Digits(s+(char)(i+'0'),n-1,sum,count+i);
        if(s.length()!=0)
         Digits(s+(char)(i+'0'),n-1,sum,count+i);
    }
}

int main() {
	// your code goes here
	int n,sum;
	cin>>n>>sum;
	string s;
	Digits(s,n,sum,0);
	return 0;
}
