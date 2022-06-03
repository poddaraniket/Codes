#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin>>s;
	int freq[26]={0};
	priority_queue<pair<int,char>> pq;
	for(int i=0;i<s.length();i++)
	 {
	     freq[s[i]-'a']++;
	 }
	for(char i='a';i<='z';i++)
	 {
	     if(freq[i-'a']>0)
	      pq.push({freq[i-'a'],i});
	 }
// 	while(!pq.empty())
// 	 {
// 	     cout<<pq.top().second<<endl;
// 	     pq.pop();
// 	 }
	string st="";
	pair<int,char> prev;
	prev.first=-1;
	prev.second='#';
	while(!pq.empty())
	 {
	     int cap=pq.top().first;
	     char u=pq.top().second;
	     //cout<<u<<endl;
	     cap--;
	     pq.pop();
	     st+=u;
	     if(prev.first>0)
	      pq.push({prev.first,prev.second});
	     prev.first=cap; 
	     prev.second=u;
	 }
	cout<<st<<endl; 
	return 0;
}
