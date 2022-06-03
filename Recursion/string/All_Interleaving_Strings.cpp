#include <bits/stdc++.h>
using namespace std;

unordered_set<string> coll;

void interleave(string temp,string a,string b)
{
    if(a.length()==0 && b.length()==0)    //Base case
     {
      coll.insert(temp);
      return; 
     }
     
    /*forget whats happening assume that when u add a 
    character at some loation it is already interleaved tii then*/ 
     
    if(a.length()!=0)
     {
        interleave(temp+a[0],a.substr(1),b); 
     }
    if(b.length()!=0)
     {
        interleave(temp+b[0],a,b.substr(1)); 
     }
}

int main() {
	// your code goes here
	string a,b;
	cin>>a>>b;
	interleave("",a,b);
	for(auto it=coll.begin();it!=coll.end();it++)
	 cout<<*it<<endl;
}
