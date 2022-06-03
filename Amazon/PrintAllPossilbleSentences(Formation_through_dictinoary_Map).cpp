#include <bits/stdc++.h>
using namespace std;


unordered_map<string,vector<string>> mp;
string dict[]={"cat", "cats", "and", "sand", "dog"};

// we use map to store the repeated part of sentences in map so that if we have to print that part again we don't have to search all over again

vector<string> wordBreak(string sent)
{
    //cout<<start<<endl;
    if(mp.find(s)!=mp.end())
        return mp[s];
    vector<string> result;
    for(int i=0;i<wordDict.size();i++)
       {
           string w=wordDict[i];
           if(s.substr(0,w.length())==w)
           {
                if(w.length()==s.length())
                   result.push_back(w);
                else
                {
                   vector<string> temp=wordBreak(s.substr(w.length()),wordDict);
                   for(int j=0;j<temp.size();j++)
                    {
                       result.push_back(w+" "+temp[j]);
                    }
                }
           }
       }
    mp[s]=result; 
    return result;
}

int main() {
	// your code goes here
	string sent;
	cin>>sent;
	//vector<string> v;
	wordBreak(sent,"",0,mp);
	return 0;
}
