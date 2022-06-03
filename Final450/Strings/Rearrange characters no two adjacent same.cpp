#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<pair<int,char>>pq;
    string s;
    cin>>s;
    int count[27]={0};
    for(int i=0;i<s.length();i++){
        count[s[i]-'a']++;
    }
    for(char i='a';i<='z';i++){
        if(count[i-'a']>0)
         pq.push({count[i-'a'],i});
    }
    string temp="";
    pair<int, char> prev;
    prev.first =-1;
    prev.second = '#';
  
    while(!pq.empty()){
        pair<int,char> k=pq.top();
        pq.pop();
        temp+=k.second;
        k.first--;
        if(prev.first>0){
            pq.push(prev);
        }
        prev=k;
    }
    if(temp.length()==s.length())
        cout<<temp<<endl;
    else
       cout<<"Not Possible"<<endl;
	return 0;
}
