//O(N)  

// Similar Q : keypad combination

#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){
    // write your code here
    if(s.length()==0)
      {
        vector<string> v;
        v.push_back("");
        return v;
      }
    char c=s[0];             // a
    string rst=s.substr(1);  // bc
    vector<string> rres=gss(rst);  // [-- , b- , bc, -c]
    
    //  a list that is initialised with values wothout a
    vector<string> myArr;
    
     // push the string without a
    for(string exclude : rres){
        myArr.push_back(exclude);
    }
    
     // we add a in those and push it again
    for(string str : rres){
        string include=c+str;
        myArr.push_back(include);
    }
    
    return myArr;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}