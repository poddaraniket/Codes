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

// we use map to store the repeated part of sentences in map so that if we have to print that part again we don't have to search all over again

void wordBreak(string sent,string res,int start,map<int,string> mp)
{
    //cout<<start<<endl;
    if(mp.find(start)!=mp.end())
     {
        cout<<res<<mp[start]<<endl;
        return;
     }
    if(start==sent.length())
    {
     cout<<res<<endl;
     return;
    }
    for(int i=start+1;i<=sent.length();i++)
     {
        string prefix=sent.substr(start,i-start);
        //cout<<prefix<<endl;
        if(dictComp(prefix))
         {
            //v.clear();
            //cout<<res<<endl;
            wordBreak(sent,res+prefix+" ",i,mp);
         }
     }
    mp[start]=res; 
    return; 
}

int main() {
	// your code goes here
	string sent;
	cin>>sent;
	//vector<string> v;
	map<int,string> mp;
	wordBreak(sent,"",0,mp);
	return 0;
}
