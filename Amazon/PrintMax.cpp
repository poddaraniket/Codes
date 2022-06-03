#include <bits/stdc++.h>
using namespace std;


int getMax(stack<int> s,vector<int> &v)
{
    if(v.size()==0)
     v.push_back(s.top());
    else
     {
        v[s.size()-1]=max(v[s.size()-2],s.top()); 
     }
    return v[s.size()-1]; 
}

int main() {
	// your code goes here
	stack<int> s;
	vector<int> v;
	s.push(20); 
    cout << getMax(s,v) << endl; 
    s.push(10); 
    cout << getMax(s,v) << endl; 
    s.push(50); 
    cout << getMax(s,v) << endl;
    s.pop(); 
    cout << v[s.size()-1] << endl;
	return 0;
}
