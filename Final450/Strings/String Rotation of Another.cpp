#include <bits/stdc++.h>
using namespace std;

bool rotate(string str,string str2){
    if(str.length()/2!=str2.length())
      return false;
      
    for(int i=0;i<str2.length();i++){
        if(str.substr(i,str2.length())==str2)
            return true;
    }
    return false;
}

int main() {
    string str1,str2;
    string temp;
    cin>>str1>>str2;
    temp=str1+str1;
    cout<<temp<<endl;
    cout<<rotate(temp,str2)<<endl;
	return 0;
}
