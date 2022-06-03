//Backtracking

#include <iostream>
using namespace std;

string temp="";

void subsequence(string s,int pos){
    cout<<temp<<endl;
    for(int i=pos;i<s.length();i++){
        //You want that character
        temp.push_back(s[i]);
        subsequence(s,i+1);
        //Bactracking
        //You don't want it[so removed it]
        temp.pop_back();
    }
}

int main() {
	// your code goes here
	string s;
	cin>>s;
	subsequence(s,0);
	return 0;
}
