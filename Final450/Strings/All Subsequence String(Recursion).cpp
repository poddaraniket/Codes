#include <iostream>
using namespace std;

void subsequence(string s,string str){
    if(s.length()==0){
        cout<<str<<endl;
        return;
    }
    
    subsequence(s.substr(1),str+s[0]);
    subsequence(s.substr(1),str);
}

int main() {
	// your code goes here
	string s;
	cin>>s;
	subsequence(s,"");
	return 0;
}
