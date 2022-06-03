#include <bits/stdc++.h>
using namespace std;

string dict[]={"cat", "cats", "and", "sand", "dog"};

bool dictComp(string a)
{
    //cout<<"*"<<endl;
    //int size=sizeof(dict)/sizeof(dict[0]);
    for(int i=0;i<5;i++)
     {
        if(dict[i]==a)
         {
            //v.push_back(a);
            return true;
         }
     }
    return false; 
}

void wordBreak(string sent,string res)
{
    if(sent.length()==0)
    {
     cout<<res<<endl;
     return;
    }
    for(int i=1;i<=sent.length();i++)
     {
        if(dictComp(sent.substr(0,i)))
         {
            //v.clear();
            wordBreak(sent.substr(i,sent.length()),res+sent.substr(0,i)+" ");
         }
     }
    return; 
}

int main() {
	// your code goes here
	string sent;
	cin>>sent;
	vector<string> v;
	wordBreak(sent,"");
	return 0;
}
