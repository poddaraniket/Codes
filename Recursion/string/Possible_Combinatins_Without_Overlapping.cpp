#include <bits/stdc++.h>
using namespace std;

void combination(string result,int n,string s,int index)
{
    if(index==n)
     {
        cout<<result<<endl;
        return;
     }
    for(int i=n-1;i>=index;i--)
     {
        string temp="{"+s.substr(index,i-index+1)+"}";
        combination(result+temp,n,s,i+1);
     }
}


int main() {
	// your code goes here
	string s;
	cin>>s;
	//vector<string> v;
	combination("",s.length(),s,0);
	return 0;
}
