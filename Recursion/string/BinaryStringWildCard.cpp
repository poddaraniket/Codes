#include <iostream>
using namespace std;

string t="";

void replace(string s,int k)
{
    if(k==s.length())
    {
     cout<<s<<endl;    
     return;
    }
    if(s[k]=='?')
     {
        for(int i=0;i<2;i++)
         {
             s[k]=i+'0';
             replace(s,k+1);
         }
        return; 
     }
    replace(s,k+1);
}

int main() {
	// your code goes here
	//string s;
	//cin>>s;
	//cout<<s.length()<<endl;;
	replace("1?11?00?1?",0);
	cout<<t<<endl;
}
