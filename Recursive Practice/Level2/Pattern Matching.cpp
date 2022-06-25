// at each level we will increase char of pattern 

#include<bits/stdc++.h>

using namespace std;

void solution(string str, string pattern, map<char,string> mp, string op){
	//write your code here
// 	cout<<op['p']<<endl;
	if(op.length()==0){
	    if(str.length()==0){
	        set<char> alreadyPrinted;
	        for(int i=0;i<pattern.length();i++){
	            if(alreadyPrinted.find(pattern[i])==alreadyPrinted.end()){
	                cout<<pattern[i]<<" -> "<<mp[pattern[i]]<<", ";
	                alreadyPrinted.insert(pattern[i]);
	            }
	        }
	        cout<<"."<<endl;
	    }
	    return;
	}
	char ch=op[0];
	string rop=op.substr(1);
// 	cout<<"*"<<rop<<endl;
	if(mp.find(ch)==mp.end()){
	    for(int i=0;i<str.length();i++){
	        string left=str.substr(0,i+1); 
	        string right=str.substr(i+1);
	       // cout<<ch<<" "<<left<<" "<<rop<<endl;
	        mp[ch]=left;
	        solution(right,pattern,mp,rop);
	        mp.erase(ch);
	    }
	}else {
	    string previousMapping=mp[ch];
	    int len=previousMapping.length();
	    if(len<=str.length()){
	       string left=str.substr(0,len); 
	       string right=str.substr(len);
	       if(left==previousMapping){
	          solution(right,pattern,mp,rop);
	       }
	    }
	}
}
int main() {
	string str;
	cin>>str;
	string pattern;
	cin>>pattern;
	map<char,string> map;
	solution(str,pattern,map,pattern);
}