#include <bits/stdc++.h>
using namespace std;

void combination(string s,char prev,int n)
{
   if(n)
    {
        for(char i=prev+1;i<='9';i++)
         {
             combination(s+i,i,n-1);
         }
    }
   else
    {
        cout<<s<<" ";
        return;
    }
   
}

int main() {
	// your code goes here
	int n;
	cin>>n;
    string s;
	//memset(arr,-1,sizeof(arr));
	combination("",'0',n);
	return 0;
}
